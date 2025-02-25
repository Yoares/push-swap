/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:05:55 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/05 19:15:50 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/*int main()
{
	int n = 152035;
	int fd = open("putnb.txt", O_CREAT | O_RDWR, 0644);
	ft_putnbr_fd(n, fd);
}*/
