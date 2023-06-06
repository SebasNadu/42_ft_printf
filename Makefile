# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 19:12:26 by johnavar          #+#    #+#              #
#    Updated: 2023/06/06 10:55:59 by johnavar         ###   ########.fr        #
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
SRC_DIR		= src/
OBJ_DIR		= objs/
INCLUDE		= ./include
LIBFT		= libft
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
RM			= rm -rf
AR			= ar -rcs

# Sources
SRC_FILES	= ft_printf ft_printf_utils flags print_char print_string \
			  print_int print_hex print_addr print_unsig number_utils
SRCS 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		= .cache_exists

#Rules

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT) all
		@cp $(LIBFT)/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJS) >/dev/null 2>&1
		@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR))"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
		@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
		@$(CC) $(CC_FLAGS) -c $< -o $@ -I$(INCLUDE)

$(OBJF):
		@mkdir -p $(OBJ_DIR)

bonus: all

clean:
		@$(RM) $(OBJ_DIR)
		@make -C $(LIBFT) clean
		@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
		@$(RM) $(NAME)
		@make -C $(LIBFT) fclean
		@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
		@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
		@norminette $(SRCS) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re bonus norm
