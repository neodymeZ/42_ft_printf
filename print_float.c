/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:37:33 by larosale          #+#    #+#             */
/*   Updated: 2020/07/05 01:57:50 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libftprintf.h"

#define IS_NAN 1
#define IS_INF 2

/*
** Handles width and flags in the specification, pointed to by "specs".
** Mofifies the "input" string accordingly and outputs the resulting string.
** Reallocates memory when needed for the resulting string.
*/

static char		*handle_width_and_flags(t_specs *specs, int *sign, char *input,
	int flag)
{
	char		*output;
	char		*temp;
	int			excess;

	output = input;
	excess = specs->width - ft_strlen(input);
	(specs->flags_plus || specs->flags_space || *sign) && flag != IS_NAN ?
		excess-- : 0;
	if (excess > 0 && specs->flags_zero && !specs->flags_minus && !flag)
		output = ft_strpad(input, '0', -1 * excess, 1);
	else if (excess > 0 && specs->flags_minus)
		output = ft_strpad(input, ' ', excess, 1);
	temp = output;
	*sign ? output = ft_strpad(temp, '-', -1, 1) : 0;
	(!*sign && specs->flags_plus && flag != IS_NAN) ? output =
		ft_strpad(temp, '+', -1, 1) : 0;
	(!*sign && !specs->flags_plus && specs->flags_space && flag != IS_NAN) ?
		output = ft_strpad(temp, ' ', -1, 1) : 0;
	if (output && (excess = specs->width - ft_strlen(output)) > 0)
	{
		temp = output;
		output = ft_strpad(temp, ' ', -1 * excess, 1);
	}
	return (output);
}

static char		*handle_g(t_specs *specs, double *arg, int *sign)
{
	int		exp;
	char	*output;
	char	*convert;

	output = NULL;
	exp = 0;
	if (!(convert = ft_convert_double(*arg, &exp)))
		return (NULL);
	ft_round_double(convert, specs->precision - 1, &exp);
	free(convert);
	if ((*arg == 0.0 || (exp >= -4 && exp < specs->precision)) &&
		!(output = ft_dtoa(*arg, 1, 2, specs->precision - exp - 1)))
		return (NULL);
	else if (!output &&
		!(output = ft_dtoa(*arg, 1, 3, specs->precision - 1)))
		return (NULL);
	if (!specs->flags_hash)
		ft_stripzeros(output);
	return (output);
}

/*
** Handles conversion of double "*arg" to the string, taking the specs
** into account and returns the resulting string. Handles precision and calls
** "handle_width_and_flags" function to handle width and flags.
** Allocates memory needed for the string.
*/

static char		*handle_conversion(t_specs *specs, double *arg, int *sign,
	int flag)
{
	char		*output;
	char		*temp;

	output = NULL;
	if ((specs->type == F || specs->type == FF) && !specs->flags_hash &&
		!(output = ft_dtoa(*arg, 1, 0, specs->precision)))
		return (NULL);
	else if ((specs->type == E || specs->type == EE) && !specs->flags_hash &&
		!output && !(output = ft_dtoa(*arg, 1, 1, specs->precision)))
		return (NULL);
	else if ((specs->type == F || specs->type == FF) && specs->flags_hash &&
		!output && !(output = ft_dtoa(*arg, 1, 2, specs->precision)))
		return (NULL);
	else if ((specs->type == E || specs->type == EE) && specs->flags_hash &&
		!output && !(output = ft_dtoa(*arg, 1, 3, specs->precision)))
		return (NULL);
	else if (!output && (specs->type == G || specs->type == GG) &&
		!(output = handle_g(specs, arg, sign)))
		return (NULL);
	if (output && (temp = output) && (specs->width > ft_strlen(output) ||
		specs->flags_plus || *sign == -1 || specs->flags_space))
		output = handle_width_and_flags(specs, sign, temp, flag);
	return (output);
}

/*
** Converts signed argument to unsigned and passes for further processing
** to the "handle_conversion" function.
** Prints the conversion result and returns the count of printed characters.
** Allocates and frees memory needed to store the resulting string.
*/

static int		generate_result(t_specs *specs, double *arg)
{
	char		*result;
	int			count_printed;
	int			sign;
	int			flag;

	sign = 0;
	flag = 0;
	if (ft_signbit(*arg))
	{
		sign = -1;
		*arg = -*arg;
	}
	if (ft_isnan(*arg))
		flag = IS_NAN;
	else if (ft_isposinf(*arg) || ft_isneginf(*arg))
		flag = IS_INF;
	if (!(result = handle_conversion(specs, arg, &sign, flag)))
		return (-1);
	if (specs->type == FF || specs->type == EE || specs->type == GG)
		ft_strconv(result, ft_toupper);
	count_printed = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (count_printed);
}

/*
** Prints the resulting string of the ft_printf %f, %e and %g conversions.
** Takes pointer to variadic arguments' list "args" as an argument and
** assigns the value of "args", converted to double, to
** the "arg" variable for further processing in the "generate_result"
** function.
** Returns the count of characters printed.
*/

int				print_float(t_specs *specs, va_list args)
{
	double	arg;

	specs->width == -1 ? specs->width = va_arg(args, int) : 0;
	specs->width < 0 ? specs->flags_minus = 1 : 0;
	specs->width < 0 ? specs->width *= -1 : 0;
	specs->precision == -1 ? specs->precision = va_arg(args, int) : 0;
	specs->precision < 0 ? specs->precision_set = 0 : 0;
	(specs->type == G || specs->type == GG) && specs->precision_set &&
	!specs->precision ? specs->precision = 1 : 0;
	!specs->precision_set ? specs->precision = 6 : 0;
	!specs->precision_set && specs->precision ? specs->precision_set = 1 : 0;
	arg = va_arg(args, double);
	return (generate_result(specs, &arg));
}
