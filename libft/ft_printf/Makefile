# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestrep <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 07:07:13 by drestrep          #+#    #+#              #
#    Updated: 2023/04/14 05:46:49 by drestrep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	ft_printf.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putptr.c			\
				ft_putnbr.c			\
				ft_unsigned_int.c	\
				ft_hexadecimal.c	\

OBJS		=	$(SRCS:.c=.o)


CC			=	gcc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror
#SRCS_PATH	= 	ft_printf_utils/

NAME		= 	libftprintf.a

all:			$(NAME)

#%.o: $(SRCS_PATH)%.c
#	$(CC) $(FLAGS) -I -c -o $@ $<

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			clean
