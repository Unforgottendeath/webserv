NAME            = libft.a

CC              = cc
FLAGS           = -Wall -Wextra -Werror
RM              = rm -rf

OBJDIR          = .objFiles

SRCDIR          = ./srcs
INCDIR          = ./includes

SRCFILES        = tcp_listen wrapsock wrapunix Writen Readn error Readline
HEADERFILES     = includes libft macros prototypes

SRC             = $(addprefix $(SRCDIR)/, $(SRCFILES:=.c))
OBJ             = $(addprefix $(OBJDIR)/, $(SRCFILES:=.o))
HEADER          = $(addprefix $(INCDIR)/, $(HEADERFILES:=.h))

# Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
else
   OPTS =
endif

# Check for kevent function
KEVENT_CHECK = $(shell echo '#include <sys/event.h>' | gcc -E - 2>/dev/null | grep -c 'kevent')

ifeq ($(KEVENT_CHECK), 1)
    CFLAGS += -DHAVE_KEVENT
endif

# Check for addrinfo structure
ADDRINFO_CHECK = $(shell echo '#include <netdb.h>' | gcc -E - 2>/dev/null | grep -c 'struct addrinfo')

ifeq ($(ADDRINFO_CHECK), 1)
    CFLAGS += -DHAVE_ADDRINFO_STRUCT
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
