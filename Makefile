# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:58:46 by janhan            #+#    #+#              #
#    Updated: 2024/02/07 12:29:06 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		push_swap

CC				=		cc -g

CFLAGS			=		#-Wall -Wextra -Werror

LIBFT_DIR		=		libft
LIBFT_A			=		libft/libft.a

SRCS_MAN		=	push_swap_file/srcs/push_swap.c \
					push_swap_file/srcs/ft_process.c \
					push_swap_file/srcs/operations_1.c \
					push_swap_file/srcs/operations_2.c \
					push_swap_file/srcs/operations_3.c \
					push_swap_file/srcs/ft_check_dup.c \
					push_swap_file/srcs/ft_check_sorted.c \
					push_swap_file/srcs/ft_error.c \
					push_swap_file/srcs/ft_stack_utils.c \
					push_swap_file/srcs/ft_stack_utils_2.c \
					push_swap_file/srcs/ft_sort_big.c \
					push_swap_file/srcs/ft_sort_utils.c	\
					push_swap_file/srcs/ft_sort_three.c \
					push_swap_file/srcs/ft_index.c		\
					push_swap_file/srcs/ft_get_cunk.c
OBJS_MAND		=	$(SRCS_MAN:.c=.o)

SRCS_BONUS		=
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

ifdef FLAG
	OBJS_FILES = $(OBJS_BONUS)
else
	OBJS_FILES = $(OBJS_MAND)
endif

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

bonus :
	make all FLAG=1

$(NAME) : $(OBJS_FILES)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) Game -" $(NONE)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_A) $^ -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJS_MAND) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re	:
	@make -C $(LIBFT_DIR)
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re