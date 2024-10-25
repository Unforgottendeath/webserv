NAME            = libft.a

CC              = cc
FLAGS           = -Wall -Wextra -Werror
RM              = rm -rf

OBJDIR          = .objFiles

SRCDIR          = ./srcs
INCDIR          = ./includes

SRCFILES        = 
HEADERFILES     = includes

SRC             = $(addprefix $(SRCDIR)/, $(SRCFILES:=.cpp))
OBJ             = $(addprefix $(OBJDIR)/, $(SRCFILES:=.o))
HEADER          = $(addprefix $(INCDIR)/, $(HEADERFILES:=.hpp))

# Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
else
   OPTS =
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
