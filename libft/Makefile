# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 16:09:09 by jmabel            #+#    #+#              #
#    Updated: 2022/01/03 15:14:57 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c\
				ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c\
				ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
				ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c\
				ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c\
				ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c\
				ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	ft_putstr_fd.c\
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c		ft_split.c\
				ft_striteri.c	ft_strmapi.c

SRCS_B		=	ft_lstnew_bonus.c			ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c			ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c			ft_lstiter_bonus.c\
				ft_lstmap_bonus.c

HEADER		=	libft.h

OBJ 		= 	$(SRCS:%.c=%.o)
OBJ_B 		= 	$(SRCS_B:%.c=%.o)
RM 			= 	rm -rf
CC 			= 	cc 
CFLAGS 		= 	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o			: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus		:	$(OBJ_B)
	make OBJ="$(OBJ_B)" all

clean 		:
	$(RM) $(OBJ) $(OBJ_B)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all