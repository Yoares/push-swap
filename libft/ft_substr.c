/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:24:12 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/11 17:43:24 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*p;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		return (ft_strdup(""));
	}
	else if (start + len > s_len)
	{
		len = s_len - start;
	}
	p = (char *)malloc(len + 1);
	if (!p)
	{
		return (NULL);
	}
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
