/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_placeholder_functs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:32:02 by larosale          #+#    #+#             */
/*   Updated: 2020/06/18 16:23:20 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Parses placeholder flags and writes their values to the "*specs" structure.
** Then shifts the pointer "*placeholder" to the next field and returns 1.
*/

int	parse_placeholder_flags(char **placeholder, t_specs *specs)
{
	char	*position;

	position = *placeholder;
	while (*position && ft_strchr(FLAGS, *position))
	{
		*position == '-' ? specs->flags_minus = 1 : 0;
		*position == '+' ? specs->flags_plus = 1 : 0;
		*position == ' ' ? specs->flags_space = 1 : 0;
		*position == '0' ? specs->flags_zero = 1 : 0;
		*position == '\'' ? specs->flags_apostrophe = 1 : 0;
		*position == '#' ? specs->flags_hash = 1 : 0;
		position++;
	}
	*placeholder = position;
	return (1);
}

/*
** Parses placeholder width and writes its value to the "*specs" structure.
** Then shifts the pointer "*placeholder" to the next field and returns 1.
*/

int	parse_placeholder_width(char **placeholder, t_specs *specs)
{
	char	*position;
	long	width;

	width = 0;
	position = *placeholder;
	if (*position == '*')
	{
		specs->width = -1;
		position++;
	}
	else
	{
		while (*position && ft_isdigit(*position))
		{
			if (width * 10 < INT_MAX)
				width = width * 10 + (*position - '0');
			else
				width = INT_MAX;
			position++;
		}
		specs->width = (int)width;
	}
	*placeholder = position;
	return (1);
}

/*
** Parses placeholder precision and writes its value to the "*specs" structure.
** Then shifts the pointer "*placeholder" to the next field and returns 1.
*/

int	parse_placeholder_precision(char **placeholder, t_specs *specs)
{
	char	*position;
	long	precision;

	precision = 0;
	position = *placeholder;
	if (*position == '.' && *(position + 1) == '*')
	{
		specs->precision_set = 1;
		specs->precision = -1;
		position += 2;
	}
	else if (*position == '.')
	{
		specs->precision_set = 1;
		while (*++position && ft_isdigit(*position))
		{
			if (precision * 10 < INT_MAX)
				precision = precision * 10 + (*position - '0');
			else
				precision = INT_MAX;
		}
		specs->precision = (int)precision;
	}
	*placeholder = position;
	return (1);
}

/*
** Parses placeholder length and writes its value (based on enum "e_length")
** to the "*specs" structure. Then shifts the pointer accordingly, returns 1.
*/

int	parse_placeholder_length(char **placeholder, t_specs *specs)
{
	char	*position;

	position = *placeholder;
	*position == 'h' ? specs->length = H : 0;
	*position == 'l' ? specs->length = L : 0;
	*position == 'L' ? specs->length = LD : 0;
	*position == 'z' ? specs->length = Z : 0;
	*position == 'j' ? specs->length = J : 0;
	*position == 't' ? specs->length = T : 0;
	*position == 'h' && *(position + 1) == 'h' ? specs->length = HH : 0;
	*position == 'l' && *(position + 1) == 'l' ? specs->length = LL : 0;
	if (specs->length)
		position++;
	if (specs->length == HH || specs->length == LL)
		position++;
	*placeholder = position;
	return (1);
}

/*
** Parses placeholder type and writes its value (based on enum "e_type")
** to the "*specs" structure. Returns 1 if type was parsed successfully and
** 0 otherwise.
*/

int	parse_placeholder_type(char **placeholder, t_specs *specs)
{
	char		*position;
	t_type		type;

	type = PER;
	position = *placeholder;
	while (type <= B)
	{
		if (*position == TYPES[type - 1])
		{
			specs->type = type;
			return (1);
		}
		type++;
	}
	return (0);
}
