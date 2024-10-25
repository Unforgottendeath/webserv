#include "../includes/webserv.hpp"

ssize_t /* Read "n" bytes from a descriptor. */
readn(int fd, void *vptr, size_t n)
{
	size_t	nleft;
	ssize_t	nread;
	char	*ptr;

	ptr = static_cast<char *>(vptr);
	nleft = n;
	while (nleft > 0)
	{
		if ((nread = read(fd, ptr, nleft)) < 0)
		{
			if (errno == EINTR)
				nread = 0;
			else
				return (-1);
		}
		else if (nread == 0)
			break ;
		nleft -= nread;
		ptr += nread;
	}
	return (n - nleft);
}

ssize_t	Readn(int fd, void *ptr, size_t nbytes)
{
	ssize_t n;

	if ((n = readn(fd, ptr, nbytes)) < 0)
		err_sys("readn error");
	return (n);
}