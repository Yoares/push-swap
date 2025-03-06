/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sop_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:47:09 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/06 21:49:21 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, int mark)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (mark)
		write(1, "rr\n", 3);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	while (lstsize(*stack_a) > 3)
	{
		min = search_min_num(*stack_a);
		while (((*stack_a)->data) != min)
		{
			rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
	pa(stack_b, stack_a, 1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
