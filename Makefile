# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:27:05 by cleblais          #+#    #+#              #
#    Updated: 2022/12/23 14:39:03 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		pipex

SRCS		=		pipex.c pi_utils.c pi_split.c pi_substr.c \
					pi_free_error.c

SRCS_BONUS	=		pipex_bonus.c pi_utils.c pi_split.c pi_substr.c \
					pi_free_error.c

OBJS		= 		$(SRCS:.c=.o)

OBJS_BONUS	=		$(SRCS_BONUS:.c=.o)

CC			=		gcc

LIB			= 		libft/libft.a ft_printf/libftprintf.a
	
CFLAGS		=		-Wall -Wextra -Werror -g

RM			= 		rm -f

all			:		$(NAME)

bonus		:		$(OBJS_BONUS) $(LIB)
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(NAME)

$(NAME)		:		$(OBJS) $(LIB)
					$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB)		:
					make -C libft
					make clean -C libft
					make -C ft_printf
					make clean -C ft_printf

clean		:
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
