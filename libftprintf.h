/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:54:16 by larosale          #+#    #+#             */
/*   Updated: 2020/07/05 02:27:25 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"

/*
**-----------------------------------PARSING------------------------------------
*/

# define TYPES "%diufFeEgGxXoscpaAnb"
# define FLAGS "-+ 0'#"

/*
** This enum type describes the "length" field in a placeholder.
** All values of enum correspond to their original counterparts in printf
** (in lowercase), except for "LD" - it corresponds to the "L" modifier.
*/

typedef	enum	e_length
{
	H = 1, HH, L, LL, LD, Z, J, T
}				t_length;

/*
** This enum type describes the "type" field in a placeholder.
** All values correspond to their original counterparts (in lowercase).
** PER stands for %, and values with two letters correspond to the uppercase
** type modifiers of printf (e. g. GG is G).
*/

typedef	enum	e_type
{
	PER = 1, D, I, U, F, FF, E, EE, G, GG, X, XX, O, S, C, P, A, AA, N, B
}				t_type;

/*
** A structure of type "t_specs" is used to store the placeholder parameters.
** "flags_" members describe flags (1 if a flag is present, 0 otherwise).
** "width" has the value of the minimum width of output, or -1 (if dynamic)
** and INT_MAX (if overflowed).
** "precision" has the value of the precision, or -1 (if dynamic),
** and INT_MAX (if overflowed).
** "precision_set" is set to 1 if precision has a value (implicit of explicit).
** "Length" and "type" has the integer values from their respective enums.
*/

typedef	struct	s_specs
{
	int			flags_plus;
	int			flags_minus;
	int			flags_space;
	int			flags_zero;
	int			flags_apostrophe;
	int			flags_hash;
	int			width;
	int			precision;
	int			precision_set;
	t_length	length;
	t_type		type;
}				t_specs;

char			**split_format_string(char const *s);
int				parse_placeholder_flags(char **placeholder, t_specs *specs);
int				parse_placeholder_width(char **placeholder, t_specs *specs);
int				parse_placeholder_precision(char **placeholder, t_specs *specs);
int				parse_placeholder_length(char **placeholder, t_specs *specs);
int				parse_placeholder_type(char **placeholder, t_specs *specs);

/*
**-----------------------------------PRINTING-----------------------------------
*/

typedef	struct	s_print
{
	int			(*print_func)(t_specs *, va_list);
	t_type		type;
}				t_print;

extern t_print	g_print_funcs[];
int				print_int(t_specs *specs, va_list args);
int				print_uint(t_specs *specs, va_list args);
int				print_string(t_specs *specs, va_list args);
int				print_ptr(t_specs *specs, va_list args);
int				handle_n(t_specs *specs, va_list args, int already_printed);
int				print_float(t_specs *specs, va_list args);
int				ft_printf(const char *format, ...);

#endif
