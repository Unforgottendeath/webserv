NAME=libft
CC=cc
CFLAGS=-Wall -Wextra
RM=rm -f
SRC = ./srcs/Readline.c ./srcs/Readn.c ./srcs/Writen.c ./srcs/connect_nonb.c ./srcs/connect_timeo.c ./srcs/daemon_inetd.c ./srcs/daemon_init.c ./srcs/dg_cli.c ./srcs/dg_echo.c ./srcs/error.c ./srcs/family_to_level.c ./srcs/gf_time.c ./srcs/host_serv.c ./srcs/hstrerror.c ./srcs/if_indextoname.c ./srcs/if_nameindex.c ./srcs/if_nametoindex.c ./srcs/in6addr_any.c ./srcs/mcast_get_if.c ./srcs/mcast_get_loop.c ./srcs/mcast_get_ttl.c ./srcs/mcast_join.c ./srcs/mcast_leave.c ./srcs/mcast_set_if.c ./srcs/mcast_set_loop.c ./srcs/mcast_set_ttl.c ./srcs/my_addrs.c ./srcs/pselect.c ./srcs/read_fd.c ./srcs/readable_timeo.c ./srcs/rtt.c ./srcs/signal.c ./srcs/signal_intr.c ./srcs/snprintf.c ./srcs/sock_bind_wild.c ./srcs/sock_cmp_addr.c ./srcs/sock_cmp_port.c ./srcs/sock_get_port.c ./srcs/sock_ntop.c ./srcs/sock_ntop_host.c ./srcs/sock_set_addr.c ./srcs/sock_set_port.c ./srcs/sock_set_wild.c ./srcs/sockatmark.c ./srcs/sockfd_to_family.c ./srcs/str_cli.c ./srcs/str_echo.c ./srcs/tcp_connect.c ./srcs/tcp_listen.c ./srcs/tv_sub.c ./srcs/udp_client.c ./srcs/udp_connect.c ./srcs/udp_server.c ./srcs/wraplib.c ./srcs/wrappthread.c ./srcs/wrapsock.c ./srcs/wrapstdio.c ./srcs/wrapunix.c ./srcs/writable_timeo.c ./srcs/write_fd.c 
		  

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ) 

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: fclean all re  clean

