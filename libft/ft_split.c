/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:13:36 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/03 20:23:37 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_all(char **ptr, size_t j)
{
	while (j > 0)
		free(ptr[--j]);
	free(ptr);
	return (NULL);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	nichan(char const *s, char c, char **ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ptr[j] = malloc(c_len(s + i, c) + 1);
			if (!ptr[j])
				return (free_all(ptr, j) == NULL);
			ft_strlcpy(ptr[j++], s + i, c_len(s + i, c) + 1);
			i += c_len(s + i, c);
		}
	}
	ptr[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	if (nichan(s, c, ptr))
		return (NULL);
	return (ptr);
}
