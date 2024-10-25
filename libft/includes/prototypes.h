#ifndef __PROTOTYPES_H__
# define __PROTOTYPES_H__

# include "libft.h"

// ======================= UNIX ======================= //

ssize_t	Readline(int fd, void *ptr, size_t maxlen);
ssize_t	Readn(int fd, void *vptr, size_t n);
ssize_t	Writen(int fd, const void *vptr, size_t n);

// ======================= ERROR ======================= //

void	err_sys(const char *fmt, ...);
void err_quit(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_ret(const char *fmt, ...);

// ======================= SOCKET ======================= //

void	Setsockopt(int fd, int level, int optname, const void *optval,
			socklen_t optlen);
int		Sockatmark(int fd);
int		Socket(int family, int type, int protocol);
void	Socketpair(int family, int type, int protocol, int *fd);
void	Sendmsg(int fd, const struct msghdr *msg, int flags);
void	Sendto(int fd, const void *ptr, size_t nbytes, int flags,
			const struct sockaddr *sa, socklen_t salen);
void	Send(int fd, const void *ptr, size_t nbytes, int flags);
int		Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
			struct timeval *timeout);
ssize_t	Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
			struct sockaddr *sa, socklen_t *salenptr);
ssize_t	Recvmsg(int fd, struct msghdr *msg, int flags);
ssize_t	Recv(int fd, void *ptr, size_t nbytes, int flags);
int		Poll(struct pollfd *fdarray, unsigned long nfds, int timeout);
void	Listen(int fd, int backlog);
int		Kevent(int kq, const struct kevent *changelist, int nchanges,
			struct kevent *eventlist, int nevents,
			const struct timespec *timeout);
int		Kqueue(void);
void	Getsockopt(int fd, int level, int optname, void *optval,
			socklen_t *optlenptr);
void	Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr);
void	Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr);
void	Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void	Bind(int fd, const struct sockaddr *sa, socklen_t salen);
int		Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);

// ======================= UNIX ======================= //

void	Close(int fd);
void	Dup2(int fd1, int fd2);
int	Fcntl(int fd, int cmd, int arg);
void	Gettimeofday(struct timeval *tv, void *foo);
pid_t	Fork(void);
int	Open(const char *pathname, int oflag, mode_t mode);
void	Pipe(int *fds);
void	Sigaddset(sigset_t *set, int signo);
void	Sigdelset(sigset_t *set, int signo);
void	Sigemptyset(sigset_t *set);
void	Sigfillset(sigset_t *set);
int	Sigismember(const sigset_t *set, int signo);
void	Sigpending(sigset_t *set);
void	Sigprocmask(int how, const sigset_t *set, sigset_t *oset);
pid_t	Wait(int *iptr);
pid_t	Waitpid(pid_t pid, int *iptr, int options);

#endif