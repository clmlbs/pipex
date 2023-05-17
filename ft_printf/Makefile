# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:27:05 by cleblais          #+#    #+#              #
#    Updated: 2022/11/18 17:36:48 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

SRCS		=		ft_put_format.c ft_putnbr_u.c ft_check_well_used.c \
					ft_putchar_c.c ft_putnbr_x.c ft_printf.c ft_putnbr_i.c \
					ft_putstr_s.c ft_putnbr_p.c

OBJS		= 		$(SRCS:.c=.o)

CC			=		gcc
	
CFLAGS		=		-Wall -Wextra -Werror -g

RM			= 		rm -f

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					ar rc $(NAME) $(OBJS)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
