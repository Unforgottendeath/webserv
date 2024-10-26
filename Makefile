GREEN = \033[1;3;32m
RED = \033[1;3;31m
YELLOW=\033[1;3;33m
RESET = \033[0m
MAGENTA = \033[1;35m
BLUE = \033[34;1;3m

CC = cc
NAME = webserv
NAME_BONUS = cub3D_bonus

CFLAGS = -Wall -Wextra  -Werror #-fsanitize=address -g

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = daytimeserv.c


OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)
	@echo -n;

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\t\t✓ $(NAME)$(RESET)"
	@echo "$(MAGENTA)Usage:\n\t$(YELLOW)./webserv$(RESET)"
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)\t\t✓ libft$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)\t\t✓ deleted objects $(NAME)$(RESET)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted objects libft$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)\t\t✓ deleted $(NAME)$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted libft$(RESET)"

re: fclean all

.PHONY: all clean fclean re