/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sop_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:47:09 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/07 21:00:09 by ykhoussi         ###   ########.fr       */
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
