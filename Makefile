# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 13:56:26 by julnolle          #+#    #+#              #
#    Updated: 2020/07/14 17:54:21 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
MAIN	=	main.c

CC		=	clang

CFLAGS +=	-Wall
CFLAGS +=	-Wextra

ifneq ($(err), no)
	CFLAGS += -Werror
endif

# Compiler Debug Flags
ifeq ($(d), 0)
	CFLAGS += -g3
else ifeq ($(d), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
else ifeq ($(d), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -Wpadded
else ifeq ($(d), 3)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -Wpadded
	CFLAGS += -pedantic
else ifeq ($(d), 4)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -Wpadded
	CFLAGS += -pedantic
	CFLAGS += -Weverything
endif

# ---------------- COL --------------- #

red			= \033[1;31m
green		= \033[1;32m
yellow		= \033[1;33m
no_color	= \033[1;0m

# ---------------- SRC --------------- #

# Main Sources
SRCS	+=	ft_atof.c
SRCS	+=	ft_atoi.c
SRCS	+=	ft_bzero.c
SRCS	+=	ft_calloc.c
SRCS	+=	ft_isalnum.c
SRCS	+=	ft_isalpha.c
SRCS	+=	ft_isascii.c
SRCS	+=	ft_isdigit.c
SRCS	+=	ft_isprint.c
SRCS	+=	ft_itoa_base.c
SRCS	+=	ft_itoa.c
SRCS	+=	ft_memccpy.c
SRCS	+=	ft_memchr.c
SRCS	+=	ft_memcmp.c
SRCS	+=	ft_memcpy.c
SRCS	+=	ft_memmove.c
SRCS	+=	ft_memset.c
SRCS	+=	ft_nbrsize_base.c
SRCS	+=	ft_nbrsize.c
SRCS	+=	ft_putchar.c
SRCS	+=	ft_putchar_fd.c
SRCS	+=	ft_putendl.c
SRCS	+=	ft_putendl_fd.c
SRCS	+=	ft_putnbr_base.c
SRCS	+=	ft_putnbr.c
SRCS	+=	ft_putnbr_fd.c
SRCS	+=	ft_put_revstr.c
SRCS	+=	ft_putstr.c
SRCS	+=	ft_putstr_fd.c
SRCS	+=	ft_split.c
SRCS	+=	ft_split_charset.c
SRCS	+=	ft_split_whitespaces.c
SRCS	+=	ft_strchr.c
SRCS	+=	ft_strcmp.c
SRCS	+=	ft_strdup.c
SRCS	+=	ft_strjoin_back.c
SRCS	+=	ft_strjoin.c
SRCS	+=	ft_strjoin_front.c
SRCS	+=	ft_strlcat.c
SRCS	+=	ft_strlcpy.c
SRCS	+=	ft_strlen.c
SRCS	+=	ft_strmapi.c
SRCS	+=	ft_strncmp.c
SRCS	+=	ft_strnstr.c
SRCS	+=	ft_strrchr.c
SRCS	+=	ft_strtrim.c
SRCS	+=	ft_substr.c
SRCS	+=	ft_tolower.c
SRCS	+=	ft_toupper.c

# Bonus Sources
BONUS	+=	ft_lstadd_back.c
BONUS	+=	ft_lstadd_front.c
BONUS	+=	ft_lstclear.c
BONUS	+=	ft_lstdelone.c
BONUS	+=	ft_lstiter.c
BONUS	+=	ft_lstlast.c
BONUS	+=	ft_lstmap.c
BONUS	+=	ft_lstnew.c
BONUS	+=	ft_lstsize.c

vpath %.c .

# ---------------- INC --------------- #

INCLUDES =	./
HEAD = $(INCLUDES)libft.h

# ---------------- OBJ --------------- #

DIR_OBJS	= ./objs/
OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))
OBJS_BONUS	= $(patsubst %.c, $(DIR_OBJS)%.o, $(BONUS))

# --------- EXEC FOR TESTINGS -------- #

EXEC		= exec
ALL_LIB		= -L. -lft

# --------- Compilation Rules -------- #

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^
			ranlib $(NAME)
			@echo "$(yellow)==> $@ linked$(no_color)"

$(OBJS): 	$(DIR_OBJS)%.o: %.c $(HEAD) Makefile | $(DIR_OBJS)
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)
			@echo "$(green)--> $@ made$(no_color)"

bonus : 	$(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME) $^
			ranlib $(NAME)
			@echo "$(green)--> $@ made$(no_color)"

$(EXEC) :	$(NAME) $(MAIN)
			$(CC) $(CFLAGS) $(MAIN) $(ALL_LIB) -o $@
			@echo "$(yellow)==> $@ made$(no_color)"

$(OBJS_BONUS):	$(DIR_OBJS)%.o: %.c $(HEAD)
				$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

$(DIR_OBJS):
	mkdir -p $@

clean:
			$(RM) -R $(DIR_OBJS)
			echo "$(red)-> $@ libft made$(no_color)"

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(EXEC)

re: 		fclean
			$(MAKE)

.PHONY:		all clean fclean re bonus exec
.SILENT:	$(OBJS) $(NAME) clean
