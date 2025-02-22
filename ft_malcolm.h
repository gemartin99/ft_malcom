#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <sys/select.h>
#include <ifaddrs.h>
#include <signal.h>
#include <sys/select.h>
#include <netinet/if_ether.h>
#include <linux/if_ether.h> 

#define BUFFER_SIZE 65536

extern int check_sigint;

struct arp_packet
{
    struct ethhdr eth;
    struct ether_arp arp;
};

typedef struct s_malcolm
{
    int v;
    int o;
    int s;
    int timeout;
    char *output;
    char *s_ip;
    char *s_mac;
    char *t_ip;
    char *t_mac;
    char iface[IFNAMSIZ];
} t_malcolm;

void	ft_bzero(void *s, size_t n);
void    handle_sigint(int sig);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void    mac_to_str(unsigned char *mac, char *mac_str);
void	*ft_memset(void *b, int c, size_t len);
void    print_hex(const void *data, size_t size, FILE *output);
void    print_help();
int     parse(char **argv);
int     parse_bonus(int argc, char **argv, t_malcolm *data);
int     is_hex(char c);
int	    ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strncpy(char *dst, const char *src, size_t dstsize);


int     listen_arp(t_malcolm *data);
int     send_arp(t_malcolm *data);

#endif