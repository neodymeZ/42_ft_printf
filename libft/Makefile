# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larosale <larosale@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 11:31:09 by larosale          #+#    #+#              #
#    Updated: 2020/07/05 01:23:45 by larosale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra
SRCS_REG	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_realloc.c ft_charstr.c ft_strpad.c ft_itoa_base.c ft_strconv.c \
			ft_memprint.c ft_wchar_to_utf8.c ft_wstr_to_utf8.c ft_isutf8.c \
			ft_substr_utf8.c ft_math_log10.c ft_math_floor.c ft_math_pow.c \
			ft_math_ipow.c ft_math_frexp.c ft_round_double.c ft_isnan.c \
			ft_isposinf.c ft_isneginf.c ft_strins.c ft_dtoa.c \
			ft_signbit.c ft_stripzeros.c ft_convert_double.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
OBJS_REG	= $(SRCS_REG:.c=.o)
DEPS		= $(SRCS_REG:.c=.d)
HEADER		= libft.h

all: $(NAME)

# $? automatic variable is used to only add the changed .o files to the
# library

$(NAME): $(OBJS_REG)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully \
	added $? to Libft.\033[0m"

# Include all .d dependency files to the Makefile

-include $(DEPS)

# Generate a dependency file for each source file

%.d: %.c $(HEADER)
	@$(CC) $(CFLAGS) $< -MM -MF $@

# Dependencies for .o files are automatically merged with the dependencies from
# .d file for each object

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

.PHONY: clean
clean:
	@rm -f $(OBJS_REG) $(DEPS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object and temp \
	files for Libft were deleted\033[0m"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a was \
	deleted.\033[0m"

.PHONY: re
re: fclean all
