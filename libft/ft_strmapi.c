/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:38:05 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/04 20:21:54 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	f(unsigned int n, char c)
{
	(void)n;
	return (char)ft_tolower(c);

}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;
	size_t	len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int	main(void)
{
	char *t = "yasserFFG";
	char *l = ft_strmapi(t, f);
	printf("%s", l);
	free(l);
}*/
