/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:58:23 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/05 19:28:05 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	f(unsigned int n, char *s)
{
	(void)n;
	*s = (char)ft_tolower(*s);
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*int	main(void)
{
	char p[] = "YASSERee";
	ft_striteri(p, f);
	printf("%s", p);
}*/
