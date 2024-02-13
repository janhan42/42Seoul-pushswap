# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:58:46 by janhan            #+#    #+#              #
#    Updated: 2024/02/14 07:49:59 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		push_swap

CC				=		cc -g

CFLAGS			=		-Wall -Wextra -Werror

LIBFT_DIR		=		libft
LIBFT_A			=		libft/libft.a

SRCS_MAIN		=	srcs/push_swap/push_swap.c
OBJS_MAIN		=	$(SRCS_MAIN:.c=.o)

SRCS_MAN		=	srcs/push_swap/ft_process.c \
					srcs/push_swap/operations_1.c \
					srcs/push_swap/operations_2.c \
					srcs/push_swap/operations_3.c \
					srcs/push_swap/ft_check_dup.c \
					srcs/push_swap/ft_check_sorted.c \
					srcs/push_swap/ft_error.c \
					srcs/push_swap/ft_stack_utils.c \
					srcs/push_swap/ft_stack_utils_2.c \
					srcs/push_swap/ft_sort_big.c \
					srcs/push_swap/ft_sort_utils.c	\
					srcs/push_swap/ft_sort_case.c \
					srcs/push_swap/ft_index.c		\
					srcs/push_swap/ft_get_cunk.c
OBJS_MAND		=	$(SRCS_MAN:.c=.o)


SRCS_BONUS		=	srcs/checker/checker.c	\
					srcs/checker/ft_error_ch.c
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)
BONUS			=	checker

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

$(NAME) : $(OBJS_MAIN) $(OBJS_FILES)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) -" $(NONE)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_A) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - MAND Complete -"$(NONE)

$(BONUS) : $(OBJS_BONUS) $(OBJS_FILES)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_A) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - BOUNS Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS)

clean :
	@rm -fr $(OBJS_MAND) $(OBJS_BONUS) $(OBJS_MAIN)
	@make clean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@rm -fr $(BONUS)
	@make fclean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re	:
	@make -C $(LIBFT_DIR)
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re
