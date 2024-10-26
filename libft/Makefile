NAME         = libft.a

CC           = cc
CFLAGS       = -Wall -Wextra -Werror -O3
RM           = rm -rf

OBJDIR       = .objFiles

SRCDIR       = ./srcs
INCDIR       = ./includes

SRCFILES     = Readline Readn Writen connect_nonb connect_timeo daemon_inetd daemon_init dg_cli dg_echo error family_to_level gf_time host_serv hstrerror if_indextoname if_nameindex if_nametoindex in6addr_any mcast_get_if mcast_get_loop mcast_get_ttl mcast_join mcast_leave mcast_set_if mcast_set_loop mcast_set_ttl my_addrs pselect read_fd readable_timeo rtt signal signal_intr snprintf sock_bind_wild sock_cmp_addr sock_cmp_port sock_get_port sock_ntop sock_ntop_host sock_set_addr sock_set_port sock_set_wild sockatmark sockfd_to_family str_cli str_echo tcp_connect tcp_listen tv_sub udp_client udp_connect udp_server wraplib wrappthread wrapsock wrapstdio wrapunix writable_timeo write_fd 

HEADERFILES  = includes macros prototypes libft rtt

SRC          = $(addprefix $(SRCDIR)/, $(SRCFILES:=.c))
OBJ          = $(addprefix $(OBJDIR)/, $(SRCFILES:=.o))
HEADER       = $(addprefix $(INCDIR)/, $(HEADERFILES:=.h))

# Debug
ifeq ($(DEBUG), 1)
   OPTS = -g
else
   OPTS =
endif

CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'sockaddr' && echo "-DHAVE_SYS_SOCKET_H")
CFLAGS += $(shell echo '#include <netinet/in.h>' | $(CC) -E - 2>/dev/null | grep -q 'sockaddr_in' && echo "-DHAVE_NETINET_IN_H")
CFLAGS += $(shell echo '#include <poll.h>' | $(CC) -E - 2>/dev/null | grep -q 'pollfd' && echo "-DHAVE_POLL_H")
CFLAGS += $(shell echo '#include <sys/select.h>' | $(CC) -E - 2>/dev/null | grep -q 'fd_set' && echo "-DHAVE_SYS_SELECT_H")
CFLAGS += $(shell echo '#include <sys/time.h>' | $(CC) -E - 2>/dev/null | grep -q 'timeval' && echo "-DHAVE_SYSTIME_H")
CFLAGS += $(shell echo '#include <time.h>' | $(CC) -E - 2>/dev/null | grep -q 'timespec' && echo "-DHAVE_TIME_H")
CFLAGS += $(shell echo '#include <sys/sysctl.h>' | $(CC) -E - 2>/dev/null | grep -q 'sysctl' && echo "-DHAVE_SYS_SYSCTL_H")
CFLAGS += $(shell echo '#include <pthread.h>' | $(CC) -E - 2>/dev/null | grep -q 'pthread_create' && echo "-DHAVE_PTHREAD_H")
CFLAGS += $(shell echo '#include <net/if_dl.h>' | $(CC) -E - 2>/dev/null | grep -q 'if_nameindex' && echo "-DHAVE_NET_IF_DL_H")
CFLAGS += $(shell echo '#include <sys/event.h>' | $(CC) -E - 2>/dev/null | grep -q 'kevent' && echo "-DHAVE_KQUEUE -DHAVE_SYS_EVENT_H")
CFLAGS += $(shell echo '#include <strings.h>' | $(CC) -E - 2>/dev/null | grep -q 'bcmp' && echo "-DHAVE_STRINGS_H")
CFLAGS += $(shell echo '#include <sys/ioctl.h>' | $(CC) -E - 2>/dev/null | grep -q 'ioctl' && echo "-DHAVE_SYS_IOCTL_H")
CFLAGS += $(shell echo '#include <sys/param.h>' | $(CC) -E - 2>/dev/null | grep -q 'MAXPATHLEN' && echo "-DHAVE_SYS_PARAM_H")
CFLAGS += $(shell echo '#include <sys/sockio.h>' | $(CC) -E - 2>/dev/null | grep -q 'SIOCGIFCONF' && echo "-DHAVE_SYS_SOCKIO_H")
CFLAGS += $(shell echo '#include <sys/filio.h>' | $(CC) -E - 2>/dev/null | grep -q 'FIONREAD' && echo "-DHAVE_SYS_FILIO_H")
CFLAGS += $(shell echo '#include <stdio.h>' | $(CC) -E - 2>/dev/null | grep -q 'snprintf' && echo "-DHAVE_SNPRINTF_PROTO")
CFLAGS += $(shell echo '#include <netdb.h>' | $(CC) -E - 2>/dev/null | grep -q 'getaddrinfo' && echo "-DHAVE_GETADDRINFO_PROTO")
CFLAGS += $(shell echo '#include <netdb.h>' | $(CC) -E - 2>/dev/null | grep -q 'getnameinfo' && echo "-DHAVE_GETNAMEINFO_PROTO")
CFLAGS += $(shell echo '#include <unistd.h>' | $(CC) -E - 2>/dev/null | grep -q 'gethostname' && echo "-DHAVE_GETHOSTNAME_PROTO")
CFLAGS += $(shell echo '#include <netdb.h>' | $(CC) -E - 2>/dev/null | grep -q 'hstrerror' && echo "-DHAVE_HSTRERROR_PROTO")
CFLAGS += $(shell echo '#include <net/if.h>' | $(CC) -E - 2>/dev/null | grep -q 'if_nametoindex' && echo "-DHAVE_IF_NAMETOINDEX_PROTO")
CFLAGS += $(shell echo '#include <arpa/inet.h>' | $(CC) -E - 2>/dev/null | grep -q 'inet_pton' && echo "-DHAVE_INET_PTON_PROTO")
CFLAGS += $(shell echo '#include <arpa/inet.h>' | $(CC) -E - 2>/dev/null | grep -q 'inet_aton' && echo "-DHAVE_INET_ATON_PROTO")
CFLAGS += $(shell echo '#include <signal.h>' | $(CC) -E - 2>/dev/null | grep -q 'pselect' && echo "-DHAVE_PSELECT_PROTO")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'sockatmark' && echo "-DHAVE_SOCKATMARK_PROTO")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'IP_MULTICAST_IF' && echo "-DMULTICAST")
CFLAGS += $(shell echo '#include <arpa/inet.h>' | $(CC) -E - 2>/dev/null | grep -q 'INET_ADDRSTRLEN' && echo "-DINET_ADDRSTRLEN")
# CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'SHUT_RD' && echo "-DSHUT_RD")
CFLAGS += $(shell echo '#include <netinet/in.h>' | $(CC) -E - 2>/dev/null | grep -q 'INADDR_NONE' && echo "-DINADDR_NONE")
CFLAGS += $(shell echo '#include <arpa/inet.h>' | $(CC) -E - 2>/dev/null | grep -q 'INET6_ADDRSTRLEN' && echo "-DINET6_ADDRSTRLEN")
CFLAGS += $(shell echo '#include <string.h>' | $(CC) -E - 2>/dev/null | grep -q 'bzero' && echo "-DHAVE_BZERO")
CFLAGS += $(shell echo '#include <netdb.h>' | $(CC) -E - 2>/dev/null | grep -q 'gethostbyname2' && echo "-DHAVE_GETHOSTBYNAME2")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'CMSG_LEN' && echo "-DCMSG_LEN")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'CMSG_SPACE' && echo "-DCMSG_SPACE")
CFLAGS += $(shell echo '#include <sys/un.h>' | $(CC) -E - 2>/dev/null | grep -q 'SUN_LEN' && echo "-DSUN_LEN")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'AF_LOCAL' && echo "-DAF_LOCAL")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'PF_LOCAL' && echo "-DPF_LOCAL")
CFLAGS += $(shell echo '#include <sys/poll.h>' | $(CC) -E - 2>/dev/null | grep -q 'INFTIM' && echo "-DINFTIM")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'sockaddr_sa_len' && echo "-DHAVE_SOCKADDR_SA_LEN")
CFLAGS += $(shell echo '#include <sys/socket.h>' | $(CC) -E - 2>/dev/null | grep -q 'sockaddr_storage' && echo "-DHAVE_STRUCT_SOCKADDR_STORAGE")
CFLAGS += $(shell echo '#include <netdb.h>' | $(CC) -E - 2>/dev/null | grep -q 'addrinfo' && echo "-DHAVE_ADDRINFO_STRUCT")
CFLAGS += $(shell echo '#include <net/if.h>' | $(CC) -E - 2>/dev/null | grep -q 'if_nameindex' && echo "-DHAVE_IF_NAMEINDEX_STRUCT")
CFLAGS += $(shell echo '#include <time.h>' | $(CC) -E - 2>/dev/null | grep -q 'timespec' && echo "-DHAVE_TIMESPEC_STRUCT")

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRC) $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
