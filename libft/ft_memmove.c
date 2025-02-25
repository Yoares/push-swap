/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:30:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/12 16:09:19 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*srrc;

	srrc = (const unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (dest > srrc && dest < srrc + len)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = srrc[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
