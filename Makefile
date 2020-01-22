# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 13:56:26 by julnolle          #+#    #+#              #
#    Updated: 2020/01/06 16:56:40 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	= 	ft_isalpha.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_isascii.c \
			ft_memcmp.c ft_strdup.c ft_strnstr.c ft_atoi.c ft_isdigit.c \
			ft_memmove.c ft_strlcat.c ft_strrchr.c ft_bzero.c ft_isprint.c \
			ft_strlcpy.c ft_tolower.c ft_isalnum.c ft_memcpy.c ft_memccpy.c \
			ft_memset.c ft_strlen.c ft_toupper.c ft_calloc.c \
			ft_substr.c ft_putendl.c ft_putnbr.c ft_putchar.c \
			ft_putstr.c ft_split.c ft_strtrim.c ft_strjoin.c \
			ft_itoa.c ft_strmapi.c ft_putnbr_base.c \
			ft_put_revstr.c ft_nbrsize.c ft_strjoin_front.c ft_strjoin_back.c \
			ft_nbrsize_base.c ft_itoa_base.c

BONUS	=	ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstnew.c \
			ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c 

INCLUDES =	./

HEAD = $(INCLUDES)libft.h

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror



all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $@ $^
			@ranlib $(NAME)
			@echo "\x1b[1m\x1b[31m-> Libft compiled\x1b[0m"

$(OBJS):	%.o: %.c $(HEAD)
			@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

bonus : 	$(OBJS_BONUS) $(OBJ)
			ar rcs $(NAME) $^
			ranlib $(NAME)

$(OBJS_BONUS):	%.o: %.c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
		   	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
