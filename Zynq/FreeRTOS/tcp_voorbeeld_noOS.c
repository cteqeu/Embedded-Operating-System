/*
 * main_vc.c
 *
 *  Created on: 21-dec.-2016
 *      Author: Vincent Claes
 */
#include <stdio.h>
#include <string.h>
#include "xparameters.h"
#include "netif/xadapter.h"
#include "platform.h"
#include "platform_config.h"
#if defined (__arm__) || defined(__aarch64__)
#include "xil_printf.h"
#endif
#include "lwip/err.h"
#include "lwip/tcp.h"
#include "xil_cache.h"

#if LWIP_DHCP==1
#include "lwip/dhcp.h"
#endif

/* defined by each RAW mode application */
void print_app_header();
int start_application();
int transfer_data();
void tcp_fasttmr(void);
void tcp_slowtmr(void);

/* missing declaration in lwIP */
void lwip_init();

#if LWIP_DHCP==1
extern volatile int dhcp_timoutcntr;
err_t dhcp_start(struct netif *netif);
#endif

extern volatile int TcpFastTmrFlag;
extern volatile int TcpSlowTmrFlag;
static struct netif server_netif;
struct netif *echo_netif;

int transfer_data() {
	return 0;
}

void print_app_header()
{
	xil_printf("\n\r\n\r-----TCP WEBCLIENT - GOOGLE for PXL DEMO ------\n\r");
}

void print_ip(char *msg, struct ip_addr *ip)
{
	print(msg);
	xil_printf("%d.%d.%d.%d\n\r", ip4_addr1(ip), ip4_addr2(ip),
			ip4_addr3(ip), ip4_addr4(ip));
}

void print_ip_settings(struct ip_addr *ip, struct ip_addr *mask, struct ip_addr *gw)
{

	print_ip("Board IP: ", ip);
	print_ip("Netmask : ", mask);
	print_ip("Gateway : ", gw);
}

#if defined (__arm__) && !defined (ARMR5)
#if XPAR_GIGE_PCS_PMA_SGMII_CORE_PRESENT == 1 || XPAR_GIGE_PCS_PMA_1000BASEX_CORE_PRESENT == 1
int ProgramSi5324(void);
int ProgramSfpPhy(void);
#endif
#endif

static void client_close(struct tcp_pcb *pcb)
{
	tcp_arg(pcb, NULL);
	tcp_sent(pcb, NULL);
	//tcp_close(pcb);
	xil_printf("-----Client End() ------\r\n");
}

static err_t client_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
	LWIP_UNUSED_ARG(arg);
	xil_printf("-----Client Sent() ------\r\n");
	//client_close(pcb);
	xil_printf("-----Client Close() ------\r\n");
	return ERR_OK;
}

err_t recv_callback(void *arg, struct tcp_pcb *tpcb,
                               struct pbuf *p, err_t err)
{
	u32_t *tempPtr;
	int i=0;
	xil_printf("Received from web:");
      if (err == ERR_OK && p != NULL) {
            tcp_recved(tpcb, p->tot_len);
            tempPtr = (u32_t *)p->payload;
            /* Print payload */
            //xil_printf("Received Packet. Length = %d \r\n ", p->len);
            xil_printf(p->payload);
            /*for(i=0; i<(p->len)/4;i++)
            {
               xil_printf(" %08x ", *(tempPtr++));
            }*/

            pbuf_free(p);
      }

      if (err == ERR_OK && p == NULL) {
                pbuf_free(p);
            client_close(tpcb);
      }
      return ERR_OK;
}

err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err)
{
	static int connection = 1;

	/* set the receive callback for this connection */
	tcp_recv(newpcb, recv_callback);

	/* just use an integer number indicating the connection id as the
	   callback argument */
	tcp_arg(newpcb, (void*)(UINTPTR)connection);

	/* increment for subsequent accepted connections */
	connection++;

	return ERR_OK;
}
static err_t callback_Connected(void *arg, struct tcp_pcb *tpcb,err_t err)
{
	xil_printf("-----in Callback_connected() ------\r\n");

	char *string ="GET /search?q=PXL HTTP/1.1\r\n"
				 "Host: www.google.be\r\n"
				 "Connection: close\r\n"
				 "\r\n";
	xil_printf(string);
	xil_printf("\n\r");
	LWIP_UNUSED_ARG(arg);
	if(err != ERR_OK)
	{
		xil_printf("-----Error in callback_connected ------\r\n");
	}
	else
	{
		tcp_sent(tpcb,client_sent);
		tcp_recv(tpcb, recv_callback);
		xil_printf("-----Sending tcp packet ------\r\n");
		//tcp_write(tpcb, string, strlen(string),0);
		tcp_write(tpcb, string, strlen(string),0);
		tcp_output(tpcb);

	}
	return err;
}
int start_application()
{
	xil_printf(" --- in start_application() ---\n\r");
	struct ip_addr ipserver;
	IP4_ADDR(&ipserver, 172,217,17,99);
	int port =80;
	struct tcp_pcb *pcb;
	err_t ret_val = ERR_BUF;
	pcb = tcp_new();
	tcp_bind(pcb,IP_ADDR_ANY,port);
	ret_val = tcp_connect(pcb,&ipserver,port,callback_Connected);
}

int main()
{
	struct ip_addr ipaddr, netmask, gw;

	/* the mac address of the board. this should be unique per board */
	unsigned char mac_ethernet_address[] =
	{ 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };

	echo_netif = &server_netif;
#if defined (__arm__) && !defined (ARMR5)
#if XPAR_GIGE_PCS_PMA_SGMII_CORE_PRESENT == 1 || XPAR_GIGE_PCS_PMA_1000BASEX_CORE_PRESENT == 1
	ProgramSi5324();
	ProgramSfpPhy();
#endif
#endif

	init_platform();

#if LWIP_DHCP==1
    ipaddr.addr = 0;
	gw.addr = 0;
	netmask.addr = 0;
#else
	/* initiliaze IP addresses to be used */
	IP4_ADDR(&ipaddr,  192, 168,   137, 10);
	IP4_ADDR(&netmask, 255, 255, 255,  0);
	IP4_ADDR(&gw,      192, 168,   137,  1);
#endif
	print_app_header();

	lwip_init();

  	/* Add network interface to the netif_list, and set it as default */
	if (!xemac_add(echo_netif, &ipaddr, &netmask,
						&gw, mac_ethernet_address,
						PLATFORM_EMAC_BASEADDR)) {
		xil_printf("Error adding N/W interface\n\r");
		return -1;
	}
	netif_set_default(echo_netif);

	/* now enable interrupts */
	platform_enable_interrupts();

	/* specify that the network if is up */
	netif_set_up(echo_netif);

#if (LWIP_DHCP==1)
	/* Create a new DHCP client for this interface.
	 * Note: you must call dhcp_fine_tmr() and dhcp_coarse_tmr() at
	 * the predefined regular intervals after starting the client.
	 */
	dhcp_start(echo_netif);
	dhcp_timoutcntr = 24;

	while(((echo_netif->ip_addr.addr) == 0) && (dhcp_timoutcntr > 0))
		xemacif_input(echo_netif);

	if (dhcp_timoutcntr <= 0) {
		if ((echo_netif->ip_addr.addr) == 0) {
			xil_printf("DHCP Timeout\r\n");
			xil_printf("Configuring default IP of 192.168.1.10\r\n");
			IP4_ADDR(&(echo_netif->ip_addr),  192, 168,   137, 10);
				IP4_ADDR(&(echo_netif->netmask), 255, 255, 255,  0);
				IP4_ADDR(&(echo_netif->gw),      192, 168,   137,  1);
		}
	}

	ipaddr.addr = echo_netif->ip_addr.addr;
	gw.addr = echo_netif->gw.addr;
	netmask.addr = echo_netif->netmask.addr;
#endif

	print_ip_settings(&ipaddr, &netmask, &gw);

	/* start the application (web server, rxtest, txtest, etc..) */
	start_application();

	/* receive and process packets */
	while (1) {
		if (TcpFastTmrFlag) {
			tcp_fasttmr();
			TcpFastTmrFlag = 0;
		}
		if (TcpSlowTmrFlag) {
			tcp_slowtmr();
			TcpSlowTmrFlag = 0;
		}
		xemacif_input(echo_netif);
		transfer_data();
	}
	/* never reached */
	cleanup_platform();

	return 0;
}
