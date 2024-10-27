#!/bin/bash

CONFIG_FILE="config.in"
HEADER_FILE="config.h"

echo "/* Generated configuration header */" > $HEADER_FILE

# Check for various headers and define corresponding macros
check_header() {
    header=$1
    macro=$2
    if echo "#include <$header>" | gcc -E - 2>/dev/null | grep -q "$3"; then
        echo "#define $macro 1" >> $HEADER_FILE
    fi
}

# Check headers
check_header "sys/socket.h" "HAVE_SYS_SOCKET_H" "sockaddr"
check_header "netinet/in.h" "HAVE_NETINET_IN_H" "sockaddr_in"
check_header "poll.h" "HAVE_POLL_H" "pollfd"
check_header "sys/select.h" "HAVE_SYS_SELECT_H" "fd_set"
check_header "sys/time.h" "HAVE_SYSTIME_H" "timeval"
check_header "time.h" "HAVE_TIME_H" "timespec"
check_header "sys/sysctl.h" "HAVE_SYS_SYSCTL_H" "sysctl"
check_header "pthread.h" "HAVE_PTHREAD_H" "pthread_create"
check_header "net/if_dl.h" "HAVE_NET_IF_DL_H" "if_nameindex"
check_header "sys/event.h" "HAVE_KQUEUE" "kevent"
check_header "strings.h" "HAVE_STRINGS_H" "bcmp"
check_header "sys/ioctl.h" "HAVE_SYS_IOCTL_H" "ioctl"
check_header "sys/param.h" "HAVE_SYS_PARAM_H" "MAXPATHLEN"
check_header "sys/sockio.h" "HAVE_SYS_SOCKIO_H" "SIOCGIFCONF"
check_header "sys/filio.h" "HAVE_SYS_FILIO_H" "FIONREAD"
check_header "stdio.h" "HAVE_SNPRINTF_PROTO" "snprintf"
check_header "netdb.h" "HAVE_GETADDRINFO_PROTO" "getaddrinfo"
check_header "netdb.h" "HAVE_GETNAMEINFO_PROTO" "getnameinfo"
check_header "unistd.h" "HAVE_GETHOSTNAME_PROTO" "gethostname"
check_header "netdb.h" "HAVE_HSTRERROR_PROTO" "hstrerror"
check_header "net/if.h" "HAVE_IF_NAMETOINDEX_PROTO" "if_nametoindex"
check_header "arpa/inet.h" "HAVE_INET_PTON_PROTO" "inet_pton"
check_header "arpa/inet.h" "HAVE_INET_ATON_PROTO" "inet_aton"
check_header "signal.h" "HAVE_PSELECT_PROTO" "pselect"
check_header "sys/socket.h" "HAVE_SOCKATMARK_PROTO" "sockatmark"
check_header "sys/socket.h" "MULTICAST" "IP_MULTICAST_IF"
check_header "arpa/inet.h" "INET_ADDRSTRLEN" "INET_ADDRSTRLEN"
check_header "netinet/in.h" "INADDR_NONE" "INADDR_NONE"
check_header "arpa/inet.h" "INET6_ADDRSTRLEN" "INET6_ADDRSTRLEN"
check_header "string.h" "HAVE_BZERO" "bzero"
check_header "netdb.h" "HAVE_GETHOSTBYNAME2" "gethostbyname2"
check_header "sys/socket.h" "CMSG_LEN" "CMSG_LEN"
check_header "sys/socket.h" "CMSG_SPACE" "CMSG_SPACE"
check_header "sys/un.h" "SUN_LEN" "SUN_LEN"
check_header "sys/socket.h" "AF_LOCAL" "AF_LOCAL"
check_header "sys/socket.h" "PF_LOCAL" "PF_LOCAL"
check_header "sys/poll.h" "INFTIM" "INFTIM"
check_header "sys/socket.h" "HAVE_SOCKADDR_SA_LEN" "sockaddr_sa_len"
check_header "sys/socket.h" "HAVE_STRUCT_SOCKADDR_STORAGE" "sockaddr_storage"
check_header "netdb.h" "HAVE_ADDRINFO_STRUCT" "addrinfo"
check_header "net/if.h" "HAVE_IF_NAMEINDEX_STRUCT" "if_nameindex"
check_header "time.h" "HAVE_TIMESPEC_STRUCT" "timespec"

echo "Configuration header generated: $HEADER_FILE"