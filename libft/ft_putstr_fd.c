/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:16:30 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/12 16:01:21 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0)
		return ;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*int	main(void)
{
	char s[] = "hello mamak";
	int fd = open("mamak..txt", O_CREAT | O_RDWR, 0644);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	ft_putstr_fd(s, fd);
	return (0);
}*/