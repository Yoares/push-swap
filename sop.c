/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:14 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:30:14 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	addfront(stack_b, tmp);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	if (lstsize(*stack) == 3)
		c = (*stack)->next->next->data;
	if (a > b && a > c)
		ra(stack);
	else if (b > a && b > c)
		rra(stack);
	a = (*stack)->data;
	b = (*stack)->next->data;
	if (a > b)
		sa(stack);
}

int	search_min_num(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
		{
			min = (stack)->data;
		}
		stack = stack->next;
	}
	return (min);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	while (lstsize(*stack_a) > 3)
	{
		min = search_min_num(*stack_a);
		while (((*stack_a)->data) != min)
		{
			rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
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
