# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:58:46 by janhan            #+#    #+#              #
#    Updated: 2024/02/07 09:31:47 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		push_swap

CC				=		cc -g

CFLAGS			=		-Wall -Wextra -Werror

LIBFT_DIR		=		libft
LIBFT_A			=		libft/libft.a

SRCS_MAN		=	srcs/push_swap/push_swap.c \
					srcs/push_swap/algorithm.c \
					srcs/push_swap/ft_add_back.c \
					srcs/push_swap/ft_stack_new.c \
					srcs/push_swap/ft_check_utils.c \
					srcs/push_swap/ft_parse.c \
					srcs/push_swap/operations.c \
					srcs/push_swap/operations_2.c \
					srcs/push_swap/operations_3.c \
					srcs/push_swap/ft_check_dup.c \
					srcs/push_swap/ft_check_sorted.c \
					srcs/push_swap/ft_error_print.c \
					srcs/push_swap/ft_free.c \
					srcs/push_swap/lst_utils.c \
					srcs/push_swap/lst_utils_2.c \
					srcs/push_swap/ft_parse_args_quoted.c \
					srcs/push_swap/ft_list_args.c \
					srcs/push_swap/ft_check_args.c \
					srcs/push_swap/ft_sort_big.c \
					srcs/push_swap/ft_sort_three.c \
					srcs/push_swap/ft_index.c		\
					srcs/push_swap/ft_get_cunk.c
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