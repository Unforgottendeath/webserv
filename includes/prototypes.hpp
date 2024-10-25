#ifndef __PROTOTYPES_HPP__
# define __PROTOTYPES_HPP__

# include "webserv.hpp"

// ======================= LIB ======================= //

ssize_t	Readline(int fd, void *ptr, size_t maxlen);
ssize_t	Readn(int fd, void *vptr, size_t n);
ssize_t	Writen(int fd, const void *vptr, size_t n);
void	err_sys(const char *fmt, ...);
#endif