/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:12:59 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/06 15:50:04 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc(i + 1);
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	i--;
	if (n < 0)
		n = n * (-1);
	while (i >= 0 && n > 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (i == 0)
		s[0] = '-';
	return (s);
}
