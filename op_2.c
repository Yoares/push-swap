/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:43:52 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/06 21:48:23 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack, int mark)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first->next;
	first->next = last->next;
	last->next = first;
	*stack = last;
	if (mark)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int mark)
{
	sa(a, 0);
	sb(b, 0);
	if (mark)
		write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int mark)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	addfront(stack_a, tmp);
	if (mark)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int mark)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	addfront(stack_b, tmp);
	if (mark)
		write(1, "pb\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int mark)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (mark)
		write(1, "rrr\n", 4);
}
