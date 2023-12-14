# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 14:26:07 by janhan            #+#    #+#              #
#    Updated: 2023/12/13 14:26:07 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		push_swap

HEAD		=		includes/

CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror

SRCS		=		srcs/

OBJS		=		$(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I(HEAD)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re