/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:40:15 by larosale          #+#    #+#             */
/*   Updated: 2020/06/19 14:34:04 by larosale         ###   ########.fr       */
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

static char		*handle_width_and_flags(t_specs *specs, int *sign, char *input)
{
	char		*output;
	char		*temp;
	int			excess;

	output = input;
	excess = specs->width - ft_strlen(input);
	(specs->flags_plus || specs->flags_space || *sign) ? excess-- : 0;
	if (excess > 0 && specs->flags_zero && !specs->flags_minus &&
		!specs->precision_set)
		output = ft_strpad(input, '0', -1 * excess, 1);
	else if (excess > 0 && specs->flags_minus)
		output = ft_strpad(input, ' ', excess, 1);
	temp = output;
	*sign ? output = ft_strpad(temp, '-', -1, 1) : 0;
	(!*sign && specs->flags_plus) ? output = ft_strpad(temp, '+', -1, 1) : 0;
	(!*sign && !specs->flags_plus && specs->flags_space) ? output =
		ft_strpad(temp, ' ', -1, 1) : 0;
	if (output && (excess = specs->width - ft_strlen(output)) > 0)
	{
		temp = output;
		output = ft_strpad(temp, ' ', -1 * excess, 1);
	}
	return (output);
}

/*
** Handles conversion of integer "*arg" to the string, taking the specs
** into account and returns the resulting string. Handles precision and calls
** "handle_width_and_flags" function to handle width and flags.
** Allocates memory needed for the string.
*/

static char		*handle_conversion(t_specs *specs, intmax_t *arg, int *sign)
{
	char		*output;
	char		*temp;
	int			excess;

	output = NULL;
	if (specs->precision_set && specs->precision == 0 && *arg == 0 &&
		!(output = ft_strdup("")))
		return (NULL);
	else if (!output && !(output = ft_itoa_base((uintmax_t)(*arg), 0, 10, 0)))
		return (NULL);
	if (output && (excess = specs->precision - ft_strlen(output)) > 0)
	{
		temp = output;
		output = ft_strpad(temp, '0', -1 * excess, 1);
	}
	if (output && (specs->width > ft_strlen(output) || specs->flags_plus ||
		*sign == -1 || specs->flags_space))
	{
		temp = output;
		output = handle_width_and_flags(specs, sign, temp);
	}
	return (output);
}

/*
** Converts int argument to unsigned value and passes for further processing
** to the "handle_conversion" function.
** Prints the conversion result and returns the count of printed characters.
** Allocates and frees memory needed to store the resulting string.
*/

static int		generate_result(t_specs *specs, intmax_t *arg)
{
	char		*result;
	int			count_printed;
	int			sign;

	sign = 0;
	if (*arg < 0)
	{
		sign = -1;
		*arg = -*arg;
	}
	if (!(result = handle_conversion(specs, arg, &sign)))
		return (-1);
	count_printed = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (count_printed);
}

/*
** Prints the resulting string of the ft_printf %d and %i conversions.
** Takes pointer to variadic arguments' list "args" as an argument and
** assigns the value of "args", converted to the respective int, to
** the "arg" variable for further processing in the "generate_result"
** function.
** Returns the count of characters printed.
*/

int				print_int(t_specs *specs, va_list args)
{
	intmax_t	arg;

	specs->width == -1 ? specs->width = va_arg(args, int) : 0;
	specs->width < 0 ? specs->flags_minus = 1 : 0;
	specs->width < 0 ? specs->width *= -1 : 0;
	specs->precision == -1 ? specs->precision = va_arg(args, int) : 0;
	specs->precision < 0 ? specs->precision_set = 0 : 0;
	if (specs->length)
	{
		specs->length == HH ? arg = (signed char)(va_arg(args, int)) : 0;
		specs->length == H ? arg = (short)(va_arg(args, int)) : 0;
		specs->length == L ? arg = va_arg(args, long) : 0;
		specs->length == LL ? arg = va_arg(args, long long) : 0;
		specs->length == Z ? arg = va_arg(args, ssize_t) : 0;
		specs->length == J ? arg = va_arg(args, intmax_t) : 0;
		specs->length == T ? arg = va_arg(args, ptrdiff_t) : 0;
	}
	else
		arg = va_arg(args, int);
	return (generate_result(specs, &arg));
}
