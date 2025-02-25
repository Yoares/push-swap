/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:16:02 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/08 17:46:05 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
	}
	return (NULL);
}
// int main()
// {
// 	const  char *s = "hello";
// 	int c = 'e';
// 	char *result = ft_strrchr(s, c);
// 	printf("%s", result);
// }
