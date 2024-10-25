#include "../includes/webserv.hpp"

void	Close(int fd)
{
	if (close(fd) == -1)
		err_sys("close error");
}

void	Dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		err_sys("dup2 error");
}

int	Fcntl(int fd, int cmd, int arg)
{
	int	n;

	if ((n = fcntl(fd, cmd, arg)) == -1)
		err_sys("fcntl error");
	return (n);
}

void	Gettimeofday(struct timeval *tv, void *foo)
{
	if (gettimeofday(tv, foo) == -1)
		err_sys("gettimeofday error");
	return ;
}

pid_t	Fork(void)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		err_sys("fork error");
	return (pid);
}

int	Open(const char *pathname, int oflag, mode_t mode)
{
	int	fd;

	if ((fd = open(pathname, oflag, mode)) == -1)
		err_sys("open error for %s", pathname);
	return (fd);
}

void	Pipe(int *fds)
{
	if (pipe(fds) < 0)
		err_sys("pipe error");
}

void	Sigaddset(sigset_t *set, int signo)
{
	if (sigaddset(set, signo) == -1)
		err_sys("sigaddset error");
}

void	Sigdelset(sigset_t *set, int signo)
{
	if (sigdelset(set, signo) == -1)
		err_sys("sigdelset error");
}

void	Sigemptyset(sigset_t *set)
{
	if (sigemptyset(set) == -1)
		err_sys("sigemptyset error");
}

void	Sigfillset(sigset_t *set)
{
	if (sigfillset(set) == -1)
		err_sys("sigfillset error");
}

int	Sigismember(const sigset_t *set, int signo)
{
	int	n;

	if ((n = sigismember(set, signo)) == -1)
		err_sys("sigismember error");
	return (n);
}

void	Sigpending(sigset_t *set)
{
	if (sigpending(set) == -1)
		err_sys("sigpending error");
}

void	Sigprocmask(int how, const sigset_t *set, sigset_t *oset)
{
	if (sigprocmask(how, set, oset) == -1)
		err_sys("sigprocmask error");
}

pid_t	Wait(int *iptr)
{
	pid_t	pid;

	if ((pid = wait(iptr)) == -1)
		err_sys("wait error");
	return (pid);
}

pid_t	Waitpid(pid_t pid, int *iptr, int options)
{
	pid_t	retpid;

	if ((retpid = waitpid(pid, iptr, options)) == -1)
		err_sys("waitpid error");
	return (retpid);
}
