/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:12:07 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/11 17:17:02 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
			{
				break ;
			}
			j++;
		}
		if (s2[j] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	while (i > 0)
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i - 1] == s2[j])
			{
				break ;
			}
			j++;
		}
		if (s2[j] == '\0')
		{
			return (i);
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new_str;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	len = end - start;
	if (start >= end)
	{
		return (ft_strdup(""));
	}
	new_str = (char *)malloc(len + 1);
	if (!new_str)
	{
		return (NULL);
	}
	ft_strlcpy(new_str, s1 + start, len + 1);
	return (new_str);
}
