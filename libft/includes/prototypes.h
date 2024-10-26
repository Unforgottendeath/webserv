#ifndef __PROTOTYPES_H__
# define __PROTOTYPES_H__

# include "libft.h"

// ======================= OUR OWN LIBRARY WRAPPER ======================= //

void				Connect_timeo(int, const SA *, socklen_t, int);
int					Family_to_level(int);
struct addrinfo		*Host_serv(const char *, const char *, int, int);
const char			*Inet_ntop(int, const void *, char *, size_t);
void				Inet_pton(int, const char *, void *);
char				*If_indextoname(unsigned int, char *);
unsigned int		If_nametoindex(const char *);
struct if_nameindex	*If_nameindex(void);
char				**My_addrs(int *);
ssize_t				Read_fd(int, void *, size_t, int *);
int					Readable_timeo(int, int);
ssize_t				Recvfrom_flags(int, void *, size_t, int *, SA *,
						socklen_t *, struct unp_in_pktinfo *);
Sigfunc				*Signal(int, Sigfunc *);
Sigfunc				*Signal_intr(int, Sigfunc *);
int					Sock_bind_wild(int, int);
char				*Sock_ntop(const SA *, socklen_t);
char				*Sock_ntop_host(const SA *, socklen_t);
int					Sockfd_to_family(int);
int					Tcp_connect(const char *, const char *);
int					Tcp_listen(const char *, const char *, socklen_t *);
int					Udp_client(const char *, const char *, SA **, socklen_t *);
int					Udp_connect(const char *, const char *);
int					Udp_server(const char *, const char *, socklen_t *);
ssize_t				Write_fd(int, void *, size_t, int);
int					Writable_timeo(int, int);
ssize_t	 Readline(int, void *, size_t);
ssize_t	 Readn(int, void *, size_t);

// ======================= STDIO WRAPPER ======================= //

void				Fclose(FILE *);
FILE				*Fdopen(int, const char *);
char				*Fgets(char *, int, FILE *);
FILE				*Fopen(const char *, const char *);
void				Fputs(const char *, FILE *);

# ifndef HAVE_SNPRINTF_PROTO
int					snprintf(char *, size_t, const char *, ...);
# endif

// ======================= ERROR ======================= //

void				err_sys(const char *fmt, ...);
void				err_quit(const char *fmt, ...);
void				err_msg(const char *fmt, ...);
void				err_dump(const char *fmt, ...);
void				err_ret(const char *fmt, ...);

// ======================= SOCKET WRAPPER ======================= //

void				Setsockopt(int fd, int level, int optname,
						const void *optval, socklen_t optlen);
int					Sockatmark(int fd);
int					Socket(int family, int type, int protocol);
void				Socketpair(int family, int type, int protocol, int *fd);
void				Sendmsg(int fd, const struct msghdr *msg, int flags);
void				Sendto(int fd, const void *ptr, size_t nbytes, int flags,
						const struct sockaddr *sa, socklen_t salen);
void				Send(int fd, const void *ptr, size_t nbytes, int flags);
int					Select(int nfds, fd_set *readfds, fd_set *writefds,
						fd_set *exceptfds, struct timeval *timeout);
ssize_t				Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
						struct sockaddr *sa, socklen_t *salenptr);
ssize_t				Recvmsg(int fd, struct msghdr *msg, int flags);
ssize_t				Recv(int fd, void *ptr, size_t nbytes, int flags);
void				Listen(int fd, int backlog);
void				Getsockopt(int fd, int level, int optname, void *optval,
						socklen_t *optlenptr);
void				Getsockname(int fd, struct sockaddr *sa,
						socklen_t *salenptr);
void				Getpeername(int fd, struct sockaddr *sa,
						socklen_t *salenptr);
void				Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void				Bind(int fd, const struct sockaddr *sa, socklen_t salen);
int					Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
uint16_t			in_cksum(uint16_t *, int);

# ifdef HAVE_INET6_RTH_INIT
int					Inet6_rth_space(int, int);
void				*Inet6_rth_init(void *, socklen_t, int, int);
void				Inet6_rth_add(void *, const struct in6_addr *);
void				Inet6_rth_reverse(const void *, void *);
int					Inet6_rth_segments(const void *);
struct in6_addr		*Inet6_rth_getaddr(const void *, int);
# endif

# ifdef HAVE_KQUEUE
int					Kqueue(void);
int					Kevent(int, const struct kevent *, int, struct kevent *,
						int, const struct timespec *);
# endif

# ifdef HAVE_POLL
int					Poll(struct pollfd *, unsigned long, int);
# endif

# ifndef HAVE_GETADDRINFO_PROTO
int					getaddrinfo(const char *, const char *,
						const struct addrinfo *, struct addrinfo **);
void				freeaddrinfo(struct addrinfo *);
char				*gai_strerror(int);
# endif

# ifndef HAVE_GETNAMEINFO_PROTO
int					getnameinfo(const SA *, socklen_t, char *, size_t, char *,
						size_t, int);
# endif

# ifndef HAVE_GETHOSTNAME_PROTO
int					gethostname(char *, int);
# endif

# ifndef HAVE_HSTRERROR_PROTO
const char			*hstrerror(int);
# endif

# ifndef HAVE_IF_NAMETOINDEX_PROTO
unsigned int		if_nametoindex(const char *);
char				*if_indextoname(unsigned int, char *);
void				if_freenameindex(struct if_nameindex *);
struct if_nameindex	*if_nameindex(void);
# endif

# ifndef HAVE_INET_PTON_PROTO
int					inet_pton(int, const char *, void *);
const char			*inet_ntop(int, const void *, char *, size_t);
# endif

# ifndef HAVE_INET_ATON_PROTO
int					inet_aton(const char *, struct in_addr *);
# endif

# ifndef HAVE_PSELECT_PROTO
int					pselect(int, fd_set *, fd_set *, fd_set *,
						const struct timespec *, const sigset_t *);
# endif

# ifndef HAVE_SOCKATMARK_PROTO
int					sockatmark(int);
# endif

# ifdef MCAST
int					mcast_leave(int, const SA *, socklen_t);
int					mcast_join(int, const SA *, socklen_t, const char *, u_int);
int					mcast_leave_source_group(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen);
int					mcast_join_source_group(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen,
						const char *ifname, u_int ifindex);
int					mcast_block_source(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen);
int					mcast_unblock_source(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen);
int					mcast_get_if(int);
int					mcast_get_loop(int);
int					mcast_get_ttl(int);
int					mcast_set_if(int, const char *, u_int);
int					mcast_set_loop(int, int);
int					mcast_set_ttl(int, int);

void				Mcast_leave(int, const SA *, socklen_t);
void				Mcast_join(int, const SA *, socklen_t, const char *, u_int);
void				Mcast_leave_source_group(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen);
void				Mcast_join_source_group(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen,
						const char *ifname, u_int ifindex);
void				Mcast_block_source(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen);
void				Mcast_unblock_source(int sockfd, const SA *src,
						socklen_t srclen, const SA *grp, socklen_t grplen);
int					Mcast_get_if(int);
int					Mcast_get_loop(int);
int					Mcast_get_ttl(int);
void				Mcast_set_if(int, const char *, u_int);
void				Mcast_set_loop(int, int);
void				Mcast_set_ttl(int, int);
# endif

// ======================= UNIX WRAPPER ======================= //

void				*Calloc(size_t, size_t);
void				Close(int);
void				Dup2(int, int);
int					Fcntl(int, int, int);
void				Gettimeofday(struct timeval *, void *);
int					Ioctl(int, int, void *);
pid_t				Fork(void);
void				*Malloc(size_t);
int					Mkstemp(char *);
void				*Mmap(void *, size_t, int, int, int, off_t);
int					Open(const char *, int, mode_t);
void				Pipe(int *fds);
ssize_t				Read(int, void *, size_t);
void				Sigaddset(sigset_t *, int);
void				Sigdelset(sigset_t *, int);
void				Sigemptyset(sigset_t *);
void				Sigfillset(sigset_t *);
int					Sigismember(const sigset_t *, int);
void				Sigpending(sigset_t *);
void				Sigprocmask(int, const sigset_t *, sigset_t *);
char				*Strdup(const char *);
long				Sysconf(int);
void				Sysctl(int *, u_int, void *, size_t *, void *, size_t);
void				Unlink(const char *);
pid_t				Wait(int *);
pid_t				Waitpid(pid_t, int *, int);
void				Write(int, void *, size_t);

// ======================= PTHREAD WRAPPER ======================= //

void	Pthread_create(pthread_t *, const pthread_attr_t *,
					   void * (*)(void *), void *);
void	Pthread_join(pthread_t, void **);
void	Pthread_detach(pthread_t);
void	Pthread_kill(pthread_t, int);

void	Pthread_mutexattr_init(pthread_mutexattr_t *);
void	Pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);
void	Pthread_mutex_init(pthread_mutex_t *, pthread_mutexattr_t *);
void	Pthread_mutex_lock(pthread_mutex_t *);
void	Pthread_mutex_unlock(pthread_mutex_t *);

void	Pthread_cond_broadcast(pthread_cond_t *);
void	Pthread_cond_signal(pthread_cond_t *);
void	Pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
void	Pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *,
							   const struct timespec *);

void	Pthread_key_create(pthread_key_t *, void (*)(void *));
void	Pthread_setspecific(pthread_key_t, const void *);
void	Pthread_once(pthread_once_t *, void (*)(void));

#endif