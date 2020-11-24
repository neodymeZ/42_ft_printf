/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:43:44 by larosale          #+#    #+#             */
/*   Updated: 2020/07/04 18:32:28 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_print			g_print_funcs[] =
{
	&print_int, D,
	&print_int, I,
	&print_uint, U,
	&print_uint, X,
	&print_uint, XX,
	&print_uint, O,
	&print_uint, B,
	&print_uint, P,
	&print_string, C,
	&print_string, S,
	&print_string, PER,
	&print_float, F,
	&print_float, E,
	&print_float, G,
	&print_float, FF,
	&print_float, EE,
	&print_float, GG,
	(void*)0, 0
};

/*
** Dispatcher function, calls a printing function which corresponds to
** the placeholder type, as defined in "specs" structure.
*/

static int		print_placeholder(t_specs *specs, va_list args, char *string,
	int already_printed)
{
	int		i;
	int		count_printed;

	i = 0;
	count_printed = 0;
	if (!specs)
	{
		ft_putstr_fd(string, 1);
		return (ft_strlen(string));
	}
	else if (specs->type == N)
		return (handle_n(specs, args, already_printed));
	while (g_print_funcs[i].print_func)
	{
		if (g_print_funcs[i].type == specs->type)
			count_printed = g_print_funcs[i].print_func(specs, args);
		i++;
	}
	return (count_printed);
}

/*
** Parses placeholder and returns a structure "placeholder_specs", which
** contains all the placeholder's parameters.
** If memory allocation fails, or if the string is not placeholder (if it
** does not begin with '%') the function returns NULL.
** Memory allocation: sizeof(t_specs) bytes.
*/

static t_specs	*parse_placeholder(char *placeholder)
{
	t_specs	*placeholder_specs;

	if (!placeholder || *placeholder++ != '%' ||
		!(placeholder_specs = ft_calloc(1, sizeof(t_specs))))
		return (NULL);
	if (parse_placeholder_flags(&placeholder, placeholder_specs) &&
		parse_placeholder_width(&placeholder, placeholder_specs) &&
		parse_placeholder_precision(&placeholder, placeholder_specs) &&
		parse_placeholder_length(&placeholder, placeholder_specs) &&
		parse_placeholder_type(&placeholder, placeholder_specs))
		return (placeholder_specs);
	else
		free(placeholder_specs);
	return (NULL);
}

/*
** Implemented over standard printf: b (binary) conversion.
** Implemented over subject: o (octal), FEG conversions; zjt lengths.
** Not implemented:
**	$ (parameter) field;
**	' (apostrophe) flag;
**	L length;
**	a, A, C, S, DOU conversions.
*/

int				ft_printf(const char *format, ...)
{
	va_list	args;
	char	**splitted_format;
	char	**splitted_to_free;
	t_specs	*specs;
	int		count[3];

	va_start(args, format);
	if (!(splitted_format = split_format_string(format)))
		return (-1);
	splitted_to_free = splitted_format;
	ft_memset(count, 0, sizeof(int) * 3);
	while (*splitted_format)
	{
		specs = parse_placeholder(*splitted_format);
		if ((count[0] =
			print_placeholder(specs, args, *splitted_format, count[1])) >= 0)
			count[1] += count[0];
		else
			count[2] = -1;
		free(*splitted_format++);
		free(specs);
	}
	va_end(args);
	free(splitted_to_free);
	return (!count[2] ? count[1] : count[2]);
}
