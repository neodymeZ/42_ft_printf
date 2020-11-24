/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:53:37 by larosale          #+#    #+#             */
/*   Updated: 2020/06/03 14:04:23 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Skips delimiters "c" in string "s" and returns a pointer to the first non-
** delimiter symbol (or to '\0' if none were found).
*/

static const char		*skip_dels(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

/*
** Counts number of characters up to the next delilmiter and returns count.
*/

static size_t			count_word_length(char const *s, char c)
{
	size_t	word_length;

	word_length = 0;
	while (*s && *s != c)
	{
		word_length++;
		s++;
	}
	return (word_length);
}

/*
** Counts number of words in string "s".
*/

static size_t			count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s == c)
		{
			s = skip_dels(s, c);
			continue;
		}
		s += count_word_length(s, c);
		word_count++;
	}
	return (word_count);
}

/*
** Frees previously allocated memory for "words" if malloc
** for the next word fails after "step".
*/

static char				**free_words(char **words, size_t step)
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
** Splits string "s", using char "c" as a delimeter. Returns an array of
** strings containing words. If the string "s" is NULL, or allocation fails,
** returns NULL. If no words were found, the returned array will consist
** only of a NULL string.
*/

char					**ft_split(char const *s, char c)
{
	char			**words;
	size_t			word_length;
	size_t			step;

	if (!s || !(words = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	step = 0;
	while (*s)
	{
		if (*s == c)
		{
			s = skip_dels(s, c);
			continue;
		}
		word_length = count_word_length(s, c);
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
