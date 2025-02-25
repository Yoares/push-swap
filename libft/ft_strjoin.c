/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:55:29 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/12 17:04:45 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	if (s2 != NULL)
		len_s2 = ft_strlen(s2);
	p = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (s1)
		ft_strlcpy(p, s1, len_s1 + 1);
	else
		p[0] = '\0';
	if (s2)
		ft_strlcat(p, s2, len_s1 + len_s2 + 1);
	return (p);
}
