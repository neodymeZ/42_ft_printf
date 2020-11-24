# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larosale <larosale@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 11:31:09 by larosale          #+#    #+#              #
#    Updated: 2020/07/05 02:22:43 by larosale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CFLAGS			= -g # -Wall -Werror -Wextra
SRCS			= ft_printf.c split_format_string.c parse_placeholder_functs.c \
				print_int.c print_uint.c print_string.c handle_n.c print_float.c
OBJS			= $(SRCS:.c=.o)
HEADER			= libftprintf.h
LIBFT			= $(LIBFT_FLDR)/libft.a
LIBFT_FLDR		= libft

all: $(NAME)

# Libft is copied and renamed to Libftprintf, necessary functions are added
# $? automatic variable is used to only add the changed .o files to the
# library

$(NAME): $(OBJS) $(LIBFT)
	@ar rc $(NAME) $(filter-out $(LIBFT),$?)
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully \
	added $? to Libftprintf.\033[0m"

# Changes in $(HEADER) cause recompilation of all object files

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< 
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_FLDR)
	@cp $(LIBFT) $(NAME)

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	@$(MAKE) -C $(LIBFT_FLDR) clean
	@rm -f $(OBJS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files for \
	Libftprintf were deleted\033[0m"

.PHONY: fclean
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libftprintf.a \
	and Libft.a were deleted.\033[0m"

.PHONY: re
re: fclean all
