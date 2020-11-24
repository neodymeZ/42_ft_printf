/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 01:30:54 by larosale          #+#    #+#             */
/*   Updated: 2020/07/03 02:30:26 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libftprintf.h"

/*
** Handles width and flags in the specification, pointed to by "specs".
** Mofifies the "input" string accordingly and outputs the resulting string.
** Reallocates memory when needed for the resulting string.
*/

static char		*handle_width_and_flags(t_specs *specs, char *input,
	uintmax_t *arg)
{
	char		*output;
	char		*temp;
	int			exc;

	output = input;
	(exc = specs->width - ft_strlen(input)) && specs->flags_hash && *arg &&
	(specs->type == X || specs->type == XX || specs->type == P) ? exc -= 2 : 0;
	if (exc > 0 && specs->flags_zero && !specs->flags_minus &&
		!specs->precision_set)
		output = ft_strpad(input, '0', -1 * exc, 1);
	else if (exc > 0 && specs->flags_minus)
		output = ft_strpad(input, ' ', exc, 1);
	if ((*arg || specs->type == P) && specs->flags_hash &&
		(specs->type == X || specs->type == XX || specs->type == P))
	{
		temp = output;
		specs->type == X || specs->type == P ?
		output = ft_strjoin("0x", temp) : 0;
		specs->type == XX ? output = ft_strjoin("0X", temp) : 0;
		free(temp);
	}
	exc = specs->width - ft_strlen(output);
	if (output && exc > 0 && (temp = output))
		output = ft_strpad(temp, ' ', -1 * exc, 1);
	return (output);
}

/*
** Handles unsigned subtypes (u, x, X, o, b) and the hash (#) flag.
** Returns a string with the respective respresentation of "*arg" integer.
** Allocates the necessary amount of memory.
*/

static char		*handle_subtypes(t_specs *specs, uintmax_t *arg)
{
	if (*arg == 0)
		return (ft_strdup("0"));
	else if (specs->type == P)
		return (ft_itoa_base(*arg, 0, 16, 0));
	else if (specs->type == U)
		return (ft_itoa_base(*arg, 0, 10, 0));
	else if (specs->type == O && !specs->flags_hash)
		return (ft_itoa_base(*arg, 0, 8, 0));
	else if (specs->type == O && specs->flags_hash)
		return (ft_itoa_base(*arg, 0, 8, 1));
	else if (specs->type == X)
		return (ft_itoa_base(*arg, 0, 16, 0));
	else if (specs->type == XX)
		return (ft_strconv(ft_itoa_base(*arg, 0, 16, 0), ft_toupper));
	else if (specs->type == B && !specs->flags_hash)
		return (ft_itoa_base(*arg, 0, 2, 0));
	else if (specs->type == B && specs->flags_hash)
		return (ft_itoa_base(*arg, 0, 2, 1));
	return (NULL);
}

/*
** Handles conversion of integer "*arg" to the string, taking the specs
** into account and returns the resulting string.
** Calls "handle_subtypes" function to convert the "*arg" integer to a string,
** Then handles precision and calls "handle_width_and_flags" function to handle
** width and flags.
** Allocates memory needed for the string.
*/

static char		*handle_conversion(t_specs *specs, uintmax_t *arg)
{
	char		*output;
	char		*temp;
	int			excess;

	output = NULL;
	if (specs->precision_set && specs->precision == 0 && *arg == 0 &&
		!(output = ft_strdup("")))
		return (NULL);
	else if (!output && !(output = handle_subtypes(specs, arg)))
		return (NULL);
	if (output && (excess = specs->precision - ft_strlen(output)) > 0)
	{
		temp = output;
		output = ft_strpad(temp, '0', -1 * excess, 1);
	}
	if (output && (specs->width > ft_strlen(output) || specs->flags_hash))
	{
		temp = output;
		output = handle_width_and_flags(specs, temp, arg);
	}
	return (output);
}

/*
** Prints the conversion result and returns the count of printed characters.
** Allocates and frees memory needed to store the resulting string.
*/

static int		generate_result(t_specs *specs, uintmax_t *arg)
{
	char		*result;
	int			count_printed;

	if (!(result = handle_conversion(specs, arg)))
		return (-1);
	count_printed = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (count_printed);
}

/*
** Prints the resulting string of the following conversions: u, o, x, X, b.
** Takes pointer to variadic arguments' list "args" as an argument and
** assigns the value of "args", converted to the respective unsigned int,
** to the "arg" variable for further processing in the "generate_result"
** function.
** Returns the count of characters printed.
*/

int				print_uint(t_specs *specs, va_list args)
{
	uintmax_t	arg;

	specs->width == -1 ? specs->width = va_arg(args, int) : 0;
	specs->width < 0 ? specs->flags_minus = 1 : 0;
	specs->width < 0 ? specs->width *= -1 : 0;
	specs->precision == -1 ? specs->precision = va_arg(args, int) : 0;
	specs->precision < 0 ? specs->precision_set = 0 : 0;
	specs->type == P ? specs->flags_hash = 1 : 0;
	specs->type == P ? specs->length = Z : 0;
	if (specs->length)
	{
		specs->length == HH ? arg = (unsigned char)(va_arg(args, unsigned int))
			: 0;
		specs->length == H ? arg = (unsigned short)(va_arg(args, unsigned int))
			: 0;
		specs->length == L ? arg = va_arg(args, unsigned long) : 0;
		specs->length == LL ? arg = va_arg(args, unsigned long long) : 0;
		specs->length == Z ? arg = va_arg(args, size_t) : 0;
		specs->length == J ? arg = va_arg(args, uintmax_t) : 0;
		specs->length == T ? arg = va_arg(args, size_t) : 0;
	}
	else
		arg = va_arg(args, unsigned int);
	return (generate_result(specs, &arg));
}
