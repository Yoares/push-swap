/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:53:14 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/06 22:41:52 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c);
	}
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
		return (c);
}
