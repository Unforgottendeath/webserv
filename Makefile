NAME            = webserv

CC              = c++
FLAGS           = -Wall -Wextra -Werror -std=c++98
RM              = rm -rf

OBJDIR          = .objFiles

SRCDIR          = ./srcs
INCDIR          = ./includes
TEMPLATEDIR     = ./templates

SRCFILES        = 
HEADERFILES     = includes
TEMPLATEFILES   = 

SRC             = $(addprefix $(SRCDIR)/, $(SRCFILES:=.cpp))
OBJ             = $(addprefix $(OBJDIR)/, $(SRCFILES:=.o))
HEADER          = $(addprefix $(INCDIR)/, $(HEADERFILES:=.hpp))
TEMPLATE        = $(addprefix $(TEMPLATEDIR)/, $(TEMPLATEFILES:=.tpp))

# Colors
GREEN           = \e[92;5;118m
YELLOW          = \e[93;5;226m
RESET           = \e[0m

# Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
else
   OPTS =
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(TEMPLATE)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(GREEN) - Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADER) $(TEMPLATE)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all
