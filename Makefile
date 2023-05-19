# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 19:12:26 by johnavar          #+#    #+#              #
#    Updated: 2023/05/20 00:34:41 by johnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Variables

NAME		= libftprintf.a
INCLUDE 	= include
SRC_DIR		= src/
OBJS_DIR	= objs/
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

# Sources

SRCS		= ft_printf.c
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)%.o : $(SRC_DIR)%.c
		@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
		@printf "\033[2K\r${GREEN}[END]${CYAN} $(NAME) $(DEF_COLOR)"
		@$(AR) $(NAME) $(OBJS) >/dev/null 2>&1

all: $(NAME)

clean:
		@rm -rf $(OBJS_DIR)

fclean: clean
		@$(RM) $(NAME)
		@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
		@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
	@norminette $(SRCS) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY: all clean fclean re bonus norm
