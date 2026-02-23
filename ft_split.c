/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:40:32 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/03 15:53:03 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (str[i] != c)
				count++;
		}
		else
		{
			if (str[i] != c && str[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	word_len(const char *str, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*copy_word(const char *str, size_t *i, char c)
{
	size_t	j;
	size_t	len;
	char	*word;

	len = word_len(str, *i, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = str[*i + j];
		j++;
	}
	word[j] = '\0';
	*i += len;
	return (word);
}

static void	free_words(char **w, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(w[i]);
		i++;
	}
	free(w);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			words[k] = copy_word(s, &i, c);
			if (!words[k])
				return (free_words(words, k), NULL);
			k++;
		}
		else
			i++;
	}
	words[k] = NULL;
	return (words);
}


