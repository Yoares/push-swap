/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:36:57 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/06 21:52:24 by ykhoussi         ###   ########.fr       */
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

void	p_checker(t_stack **st_a, t_stack **st_b, char *op)
{
	if (!ft_strcmp(op, "pa\n"))
		pa(st_a, st_b, 0);
	else if (!ft_strcmp(op, "pb\n"))
		pb(st_a, st_b, 0);
	else if (!ft_strcmp(op, "ra\n"))
		ra(st_a, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(st_b, 0);
	else if (!ft_strcmp(op, "sa\n"))
		sa(st_a, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(st_b, 0);
	else if (!ft_strcmp(op, "rr\n"))
		rr(st_a, st_b, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(st_a, st_b, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(st_a, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(st_b, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(st_a, st_b, 0);
	else
		(free(op), free_stack(st_a), free_stack(st_b), pr_err());
}

int	main(int ac, char **av)
{
	t_stack	*st_a;
	t_stack	*st_b;
	char	*op;

	st_a = NULL;
	st_b = NULL;
	if (ac == 1)
		return (1);
	if (!parc_args(ac, av, &st_a))
		error_exit(&st_a, &st_b);
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		p_checker(&st_a, &st_b, op);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(st_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&st_a);
	free_stack(&st_b);
}
