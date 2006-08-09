#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <byteswap.h>
#include <gpxe/pkbuff.h>
#include <gpxe/netdevice.h>
#include <gpxe/in.h>
#include <gpxe/if_ether.h>
#include <gpxe/tcpip.h>

/**
 * Transmit IP6 packets
 */
static int ipv6_tx ( struct pk_buff *pkb,
		     struct tcpip_protocol *tcpip_protocol,
		     struct sockaddr_tcpip *st_dest ) {
	return -ENOSYS;
}

/**
 * Process incoming IP6 packets
 *
 * Placeholder function. Should rewrite in net/ipv6.c
 */
static int ipv6_rx ( struct pk_buff *pkb __unused,
		     struct net_device *netdev __unused,
		     const void *ll_source __unused ) {
	return -ENOSYS;
}

static const char * ipv6_ntoa ( const void *net_addr ) {
//	return inet6_ntoa ( * ( ( struct in6_addr * ) net_addr ) );
	return "no support yet";
}

/** IPv6 protocol */
struct net_protocol ipv6_protocol __net_protocol = {
	.name = "IP6",
	.net_proto = htons ( ETH_P_IPV6 ),
	.net_addr_len = sizeof ( struct in6_addr ),
	.rx = ipv6_rx,
	.ntoa = ipv6_ntoa,
};

/** IPv6 TCPIP net protocol */
struct tcpip_net_protocol ipv6_tcpip_protocol __tcpip_net_protocol = {
	.name = "IPv6",
	.sa_family = AF_INET6,
	.tx = ipv6_tx,
};
