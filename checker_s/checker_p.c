/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:36:57 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/05 21:11:12 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_h.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int main(int ac, char **av)
{
	t_stack **a;
	
    if (ac == 1)
		return 1;
	
}