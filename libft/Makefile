NAME            = libft.a

CC              = cc
FLAGS           = -Wall -Wextra -Werror
RM              = rm -rf

OBJDIR          = .objFiles

SRCDIR          = ./srcs
INCDIR          = ./includes

SRCFILES        = tcp_listen wrapsock wrapunix Writen Readn error Readline
HEADERFILES     = includes libft macros prototypes addrinfo

SRC             = $(addprefix $(SRCDIR)/, $(SRCFILES:=.c))
OBJ             = $(addprefix $(OBJDIR)/, $(SRCFILES:=.o))
HEADER          = $(addprefix $(INCDIR)/, $(HEADERFILES:=.h))

# Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
else
   OPTS =
endif

# Function to check for feature availability
check_feature = \
    (echo '\#include <$(1)>' | $(CC) -E - 2>/dev/null | grep -q '$(2)')

# Check for sockaddr
ifeq ($(shell $(check_feature sys/socket.h sockaddr)),)
CFLAGS += -DHAVE_SYS_SOCKET_H
endif

# Check for sockaddrin
ifeq ($(shell $(check_feature netinet/in.h sockaddr_in)),)
CFLAGS += -DHAVE_NETINET_IN_H
endif

# Check for pollfd
ifeq ($(shell $(check_feature poll.h pollfd)),) 
CFLAGS += -DHAVE_POLL_H
endif

# Check for fd_set
ifeq ($(shell $(check_feature sys/select.h fd_set)),)
CFLAGS += -DHAVE_SYS_SELECT_H
endif

# Check for timeval and timespec
ifeq ($(shell $(check_feature sys/time.h timeval)),) && ifeq ($(shell $(check_feature time.h timespec)),)
CFLAGS += -DTIME_WITH_SYS_TIME
endif

# Check for timeval
ifeq ($(shell $(check_feature time.h timespec)),)
CFLAGS += -DHAVE_SYSTIME_H
endif

# Check for sysctl
ifeq ($(shell $(check_feature sys/sysctl.h sysctl)),)
CFLAGS += -DHAVE_SYS_SYSCTL_H
endif

# Check for pthreadcreate
ifeq ($(shell $(check_feature pthread.h pthread_create)),)
CFLAGS += -DHAVE_PTHREAD_H
endif

# Check for if_nameindex
ifeq ($(shell $(check_feature net/if_dl.h if_nameindex)),)
CFLAGS += -DHAVE_NET_IF_DL_H
endif

# Check for kevent
ifeq ($(shell $(check_feature sys/event.h kevent)),)
CFLAGS += -DHAVE_KQUEUE -DHAVE_SYS_EVENT_H
endif

# Check for bcmp
ifeq ($(shell $(check_feature strings.h bcmp)),)
CFLAGS += -DHAVE_STRINGS_H
endif

# Check for ioctl
ifeq ($(shell $(check_feature sys/ioctl.h ioctl)),)
CFLAGS += -DHAVE_SYS_IOCTL_H
endif

# Check for sys/param.h and MAXPATHLEN
ifeq ($(shell $(check_feature sys/param.h MAXPATHLEN)),)
CFLAGS += -DHAVE_SYS_PARAM_H

# Check for sys/sockio.h and SIOCGIFCONFIG
ifeq ($(shell $(check_feature sys/sockio.h SIOCGIFCONF)),)
CFLAGS += -DHAVE_SYS_SOCKIO_H
endif

# Check for sys/filio.h and FIONREAD
ifeq ($(shell $(check_feature sys/filio.h FIONREAD)),)
CFLAGS += -DHAVE_SYS_FILIO_H
endif

# Check for snprintf
ifeq ($(shell $(check_feature stdio.h snprintf)),)
CFLAGS += -DHAVE_SNPRINTF_PROTO
endif

# Check for getaddrinfo
ifeq ($(shell $(check_feature netdb.h getaddrinfo)),)
CFLAGS += -DHAVE_GETADDRINFO_PROTO
endif

# Check for getnameinfo
ifeq ($(shell $(check_feature netdb.h getnameinfo)),)
CFLAGS += -DHAVE_GETNAMEINFO_PROTO
endif

# Check for gethostname
ifeq ($(shell $(check_feature unistd.h gethostname)),)
CFLAGS += -DHAVE_GETHOSTNAME_PROTO
endif

# Check for hstrerror
ifeq ($(shell $(check_feature netdb.h hstrerror)),)
CFLAGS += -DHAVE_HSTRERROR_PROTO
endif

# Check for if_nametoindex
ifeq ($(shell $(check_feature net/if.h if_nametoindex)),)
CFLAGS += -DHAVE_IF_NAMETOINDEX_PROTO
endif

# Check for inet_pton
ifeq ($(shell $(check_feature arpa/inet.h inet_pton)),)
CFLAGS += -DHAVE_INET_PTON_PROTO
endif

# Check for inet_aton
ifeq ($(shell $(check_feature arpa/inet.h inet_aton)),)
CFLAGS += -DHAVE_INET_ATON_PROTO
endif

# Check for pselect
ifeq ($(shell $(check_feature signal.h pselect)),)
CFLAGS += -DHAVE_PSELECT_PROTO
endif

# Check for sockatmark
ifeq ($(shell $(check_feature sys/socket.h sockatmark)),)
CFLAGS += -DHAVE_SOCKATMARK_PROTO
endif

# Check for multicasting
ifeq ($(shell $(check_feature sys/socket.h IP_MULTICAST_IF)),) && ifeq ($(shell $(check_feature arpa/inet.h inet_pton)),)
CFLAGS += -DMCAST
endif

# Check for INET_ADDRSTRLEN
ifeq ($(shell $(check_feature arpa/inet.h INET_ADDRSTRLEN)),)
CFLAGS += -DINET_ADDRSTRLEN
endif

# Check for SHUT_RD
ifeq ($(shell $(check_feature sys/socket.h SHUT_RD)),)
CFLAGS += -DSHUT_RD
endif

# Check for INADDR_NONE
ifeq ($(shell $(check_feature netinet/in.h INADDR_NONE)),)
CFLAGS += -DINADDR_NONE
endif

# Check for INET6_ADDRSTRLEN
ifeq ($(shell $(check_feature arpa/inet.h INET6_ADDRSTRLEN)),)
CFLAGS += -DINET6_ADDRSTRLEN
endif

# Check for HAVE_BZERO
ifeq ($(shell $(check_feature string.h bzero)),)
CFLAGS += -DHAVE_BZERO
endif

# Check for HAVE_GETHOSTBYNAME2
ifeq ($(shell $(check_feature netdb.h gethostbyname2)),)
CFLAGS += -DHAVE_GETHOSTBYNAME2
endif

# Check for CMSG_LEN
ifeq ($(shell $(check_feature sys/socket.h CMSG_LEN)),)
CFLAGS += -DCMSG_LEN
endif

# Check for CMSG_SPACE
ifeq ($(shell $(check_feature sys/socket.h CMSG_SPACE)),)
CFLAGS += -DCMSG_SPACE
endif

# Check for SUN_LEN
ifeq ($(shell $(check_feature sys/un.h SUN_LEN)),)
CFLAGS += -DSUN_LEN
endif

# Check for AF_LOCAL
ifeq ($(shell $(check_feature sys/socket.h AF_LOCAL)),)
CFLAGS += -DAF_LOCAL
endif

# Check for PF_LOCAL
ifeq ($(shell $(check_feature sys/socket.h PF_LOCAL)),)
CFLAGS += -DPF_LOCAL
endif

# Check for INFTIM
ifeq ($(shell $(check_feature sys/poll.h INFTIM)),)
CFLAGS += -DINFTIM
endif

# Check for HAVE_SOCKADDR_SA_LEN
ifeq ($(shell $(check_feature sys/socket.h sockaddr_sa_len)),)
CFLAGS += -DHAVE_SOCKADDR_SA_LEN
endif

# Check for HAVE_STRUCT_SOCKADDR_STORAGE
ifeq ($(shell $(check_feature sys/socket.h sockaddr_storage)),)
CFLAGS += -DHAVE_STRUCT_SOCKADDR_STORAGE
endif

# Check for HAVE_ADDRINFO_STRUCT
ifeq ($(shell $(check_feature netdb.h addrinfo)),)
CFLAGS += -DHAVE_ADDRINFO_STRUCT
endif

# Check for HAVE_IF_NAMEINDEX_STRUCT
ifeq ($(shell $(check_feature net/if.h if_nameindex)),)
CFLAGS += -DHAVE_IF_NAMEINDEX_STRUCT
endif

# Check for HAVE_TIMESPEC_STRUCT
ifeq ($(shell $(check_feature time.h timespec)),)
CFLAGS += -DHAVE_TIMESPEC_STRUCT
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) $(TEMPLATE)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
