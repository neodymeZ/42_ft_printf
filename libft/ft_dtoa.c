/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:51:49 by larosale          #+#    #+#             */
/*   Updated: 2020/07/05 02:24:41 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Generates string with exponent notation (for TYPE_E) to be used
** in "format_result" function.
*/

static char		*generate_exp_str(int exp)
{
	char	*exp_str;
	char	*temp;

	exp_str = NULL;
	temp = ft_itoa(exp >= 0 ? exp : -exp);
	if (exp >= 0 && exp <= 9)
		exp_str = ft_strjoin("e+0", temp);
	else if (exp < 0 && exp >= -9)
		exp_str = ft_strjoin("e-0", temp);
	else if (exp > 9)
		exp_str = ft_strjoin("e+", temp);
	else if (exp < 9)
		exp_str = ft_strjoin("e-", temp);
	free(temp);
	return (exp_str);
}

/*
** Formats the output of "round_result" function (adds decimal point,
** exponent notation for TYPE_E, leading zeroes for TYPE_F).
** Returns the resulting formatted string.
*/

static char		*format_result(char *input, int exp, int precision,
	int type)
{
	char	*temp;
	char	*output;
	char	*exp_str;

	temp = input;
	if ((type == F_HASH || type == F_NOHASH) && exp < 0 &&
		!(temp = ft_strpad(input, '0', exp, FREE)))
		return (NULL);
	if (exp > 0 && ((type == F_NOHASH && precision) || type == F_HASH))
		output = ft_strins(temp, '.', exp + 1);
	else if (precision || type == F_HASH || type == E_HASH)
		output = ft_strins(temp, '.', 1);
	else
		output = ft_strdup(temp);
	free(temp);
	if (type == E_HASH || type == E_NOHASH)
	{
		temp = output;
		exp_str = generate_exp_str(exp);
		output = ft_strjoin(temp, exp_str);
		free(temp);
		free(exp_str);
	}
	return (output);
}

/*
** Rounds the output of "ft_convert_double" function (string of digits)
** to the specified "precision", taking into account the conversion
** type and exponent.
** Returns the string with rounded number.
*/

static char		*round_result(char *input, int *exponent,
	unsigned int precision, int type)
{
	char	*result;
	int		exp_tmp;

	result = input;
	if ((type == F_HASH || type == F_NOHASH) && (int)precision + *exponent >= 0)
		precision += *exponent;
	else if ((type == F_HASH || type == F_NOHASH)
		&& (int)precision + *exponent < 0)
	{
		result = ft_strpad(input, '0', (int)precision + *exponent, 1);
		*exponent = -(int)precision;
		precision = 0;
	}
	if (ft_strlen(result) < precision + 1)
	{
		result = ft_strpad(input, '0', precision - ft_strlen(input) + 1, 1);
		return (result);
	}
	exp_tmp = *exponent;
	ft_round_double(result, precision, exponent);
	if ((type == F_HASH || type == F_NOHASH) && (*exponent != exp_tmp) &&
		(*(result + precision + 1) = '0'))
		*(result + precision + 2) = '\0';
	return (result);
}

/*
** Converts "input" (non-negative number, sign should be specified separately
** in "sign" parameter as SIGN_PLUS(1) or SIGN_MINUS(-1)) to string.
** The output can be represented in a fixed-point (with "type" specified as
** TYPE_F(0)), or a scientific (TYPE_E(1)) notation.
** The "precision" specifies number of digits in fraction part to be kept.
** Rounding is performed, if necessary.
** If "flag" is set to DOT_FORCE(1), decimal dot is always inserted.
*/

char			*ft_dtoa(double input, int sign, int type,
	unsigned int precision)
{
	char	*conv_res;
	char	*round_res;
	char	*format_res;
	int		exponent;

	if (input < 0)
		return (NULL);
	if (ft_isnan(input))
		return (ft_strdup("nan"));
	else if (ft_isposinf(input * sign))
		return (ft_strdup("inf"));
	else if (ft_isneginf(input * sign))
		return (ft_strdup("-inf"));
	if (!(conv_res = ft_convert_double(input, &exponent)))
		return (NULL);
	if (!(round_res = round_result(conv_res, &exponent, precision, type)))
		return (NULL);
	if (!(format_res =
		format_result(round_res, exponent, precision, type)))
		return (NULL);
	if (sign == SIGN_MINUS)
		format_res = ft_strpad(format_res, '-', -1, FREE);
	return (format_res);
}
