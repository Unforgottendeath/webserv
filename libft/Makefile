NAME         = webserv

CC           = cc
CFLAGS       = -Wall -Wextra -Werror -O3
RM           = rm -rf

CONFIG_H 	 = config.h
CONFIG_SCRIPT = ./generate_config.sh

OBJDIR       = .objFiles

SRCDIR       = ./srcs
INCDIR       = ./includes

SRCFILES     = Readline error

HEADERFILES  = libft rtt

SRC          = $(addprefix $(SRCDIR)/, $(SRCFILES:=.c)) test.c
OBJ          = $(addprefix $(OBJDIR)/, $(SRCFILES:=.o))
HEADER       = $(addprefix $(INCDIR)/, $(HEADERFILES:=.h))

# Debug
ifeq ($(DEBUG), 1)
   OPTS = -g
else
   OPTS =
endif

.PHONY: all clean fclean re

all: $(CONFIG_H) $(NAME)

$(CONFIG_H):
	@$(CONFIG_SCRIPT)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(SRC) $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
