# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 13:56:26 by julnolle          #+#    #+#              #
#    Updated: 2021/08/18 16:17:14 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
MAIN	=	./srcs/main.c

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

# Other Sources
SRCS	+=	ft_nbrsize_base.c
SRCS	+=	ft_nbrsize.c
SRCS	+=	ft_tolower.c
SRCS	+=	ft_toupper.c

# String Sources
SRCS	+=	ft_strchr.c
SRCS	+=	ft_strcmp.c
SRCS	+=	ft_strdup.c
SRCS	+=	ft_strjoin.c
SRCS	+=	ft_strjoin_front.c
SRCS	+=	ft_strjoin_back.c
SRCS	+=	ft_strlcat.c
SRCS	+=	ft_strlcpy.c
SRCS	+=	ft_strlen.c
SRCS	+=	ft_strmapi.c
SRCS	+=	ft_strncmp.c
SRCS	+=	ft_strnstr.c
SRCS	+=	ft_strrchr.c
SRCS	+=	ft_strtrim.c
SRCS	+=	ft_substr.c
SRCS	+=	ft_split.c
SRCS	+=	ft_split_charset.c
SRCS	+=	ft_split_whitespaces.c
SRCS	+=	free_tab_str.c

# Memory Sources
SRCS	+=	ft_bzero.c
SRCS	+=	ft_calloc.c
SRCS	+=	ft_memccpy.c
SRCS	+=	ft_memchr.c
SRCS	+=	ft_memcmp.c
SRCS	+=	ft_memcpy.c
SRCS	+=	ft_memmove.c
SRCS	+=	ft_memset.c

# Char test Sources
SRCS	+=	ft_isalnum.c
SRCS	+=	ft_isalpha.c
SRCS	+=	ft_isascii.c
SRCS	+=	ft_isdigit.c
SRCS	+=	ft_isprint.c
SRCS	+=	ft_isspace.c
SRCS	+=	ft_isblank.c
SRCS	+=	ft_isupper.c
SRCS	+=	ft_islower.c
SRCS	+=	ft_isdigit_str.c

# Conversion Sources
SRCS	+=	ft_atoi.c
SRCS	+=	ft_atof.c
SRCS	+=	ft_itoa.c
SRCS	+=	ft_itoa_base.c

# Print Sources
SRCS	+=	ft_putchar.c
SRCS	+=	ft_putchar_fd.c
SRCS	+=	ft_putendl.c
SRCS	+=	ft_putendl_fd.c
SRCS	+=	ft_putnbr.c
SRCS	+=	ft_putnbr_fd.c
SRCS	+=	ft_putnbr_base.c
SRCS	+=	ft_putstr.c
SRCS	+=	ft_putstr_fd.c
SRCS	+=	ft_put_revstr.c
SRCS	+=	print_tab_str.c

# GNL Sources
SRCS	+=	get_next_line.c

# ft_printf Sources
SRCS	+=	ft_printf.c
SRCS	+=	ft_printf_handle.c
SRCS	+=	ft_printf_utils.c
SRCS	+=	ft_printf_conversions.c
SRCS	+=	ft_printf_itoas.c 

# List Sources
LIST	+=	ft_lstadd_back.c
LIST	+=	ft_lstadd_front.c
LIST	+=	ft_lstclear.c
LIST	+=	ft_lstdelone.c
LIST	+=	ft_lstiter.c
LIST	+=	ft_lstlast.c
LIST	+=	ft_lstmap.c
LIST	+=	ft_lstnew.c
LIST	+=	ft_lstsize.c
LIST	+=	tab_to_lst.c
# LIST	+=	ft_sort_list_by_key.c

vpath %.c ./srcs/
vpath %.c ./srcs/char_test/
vpath %.c ./srcs/conversion/
vpath %.c ./srcs/memory/
vpath %.c ./srcs/print/
vpath %.c ./srcs/string/
vpath %.c ./srcs/get_next_line/
vpath %.c ./srcs/ft_printf/
vpath %.c ./srcs/list/

# ---------------- INC --------------- #

INCLUDES	=	./includes/
HEAD		=	$(INCLUDES)libft.h

# ---------------- OBJ --------------- #

DIR_OBJS	= ./objs/
OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))
OBJS_LIST	= $(patsubst %.c, $(DIR_OBJS)%.o, $(LIST))

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

list : 	$(OBJS) $(OBJS_LIST)
			ar rcs $(NAME) $^
			ranlib $(NAME)
			@echo "$(yellow)==> $(NAME) with $@ linked$(no_color)"

$(EXEC) :	$(NAME) $(MAIN)
			$(CC) $(CFLAGS) $(MAIN) $(ALL_LIB) -I$(INCLUDES) -o $@
			@echo "$(yellow)==> $@ made$(no_color)"

$(OBJS_LIST):	$(DIR_OBJS)%.o: %.c $(HEAD)
				$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)
				@echo "$(green)--> $@ made$(no_color)"

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

.PHONY:		all clean fclean re list exec
.SILENT:	$(OBJS) $(OBJS_LIST) $(NAME) list clean
