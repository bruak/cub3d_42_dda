/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:38:47 by hcoskun42         #+#    #+#             */
/*   Updated: 2024/07/20 17:05:02 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../memory-allocator/allocator.h"

static int	wlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

char	**free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		safe_free(result[i]);
		i++;
	}
	safe_free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_index;

	if (!s)
		return (NULL);
	word_index = 0;
	result = (char **) safe_malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[word_index] = ft_substr(s, 0, wlen(s, c));
			if (!result[word_index++])
				return (free_array(result));
			s += wlen(s, c);
		}
	}
	result[word_index] = NULL;
	return (result);
}
