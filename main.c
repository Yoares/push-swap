/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:29:33 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:29:33 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!parc_args(ac, av, &stack_a))
		error_exit(&stack_a, &stack_b);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	if (lstsize(stack_a) == 1)
		return (0);
	if (lstsize(stack_a) <= 3)
		sort_three(&stack_a);
	else if (lstsize(stack_a) <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sorting_st(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
