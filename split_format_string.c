/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_format_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:02:19 by larosale          #+#    #+#             */
/*   Updated: 2020/07/03 12:09:38 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Counts number of characters in the current word (placeholder or plain text
** part of the format string) and returns count.
*/

static int			count_word_length(char const *s)
{
	int				word_length;

	word_length = 0;
	if (*s != '%')
	{
		while (*s && *s != '%')
		{
			word_length++;
			s++;
		}
	}
	else
	{
		word_length++;
		while (*++s)
		{
			if (ft_strchr(TYPES, *s))
			{
				word_length++;
				break ;
			}
			word_length++;
		}
	}
	return (word_length);
}

/*
** Counts number of words in string "s".
*/

static int			count_words(char const *s)
{
	int				word_count;

	word_count = 0;
	while (*s)
	{
		s += count_word_length(s);
		word_count++;
	}
	return (word_count);
}

/*
** Frees previously allocated memory for "words" if malloc
** for the next word fails after "step".
*/

static char			**free_words(char **words, size_t step)
{
	while (step > 0)
	{
		words--;
		free(*words);
		step--;
	}
	free(words);
	return (NULL);
}

/*
** Splits string "s", using char "%" as a delimeter. Returns an array of
** strings containing words. If the string "s" is NULL, or allocation fails,
** returns NULL. If no words were found, the returned array will consist
** only of a NULL string.
*/

char				**split_format_string(char const *s)
{
	char			**words;
	int				word_length;
	int				step;

	if (!s || !(words = malloc((count_words(s) + 1) * sizeof(char *))))
		return (NULL);
	step = 0;
	while (*s)
	{
		word_length = count_word_length(s);
		if (!(*words = malloc(word_length + 1)))
			return (free_words(words, step));
		ft_strlcpy(*words, s, word_length + 1);
		s += word_length;
		words++;
		step++;
	}
	*words = NULL;
	return (words - step);
}
