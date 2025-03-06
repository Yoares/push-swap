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
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	addfront(stack_b, tmp);
}

int	get_max_indx(t_stack *st)
{
	int	max_indx;

	if (!st)
		return (0);
	max_indx = st->index;
	while (st)
	{
		if (st->index > max_indx)
			max_indx = st->index;
		st = st->next;
	}
	return (max_indx);
}

void	sort_three(t_stack **st)
{
	int	max_idx;

	if (!(*st) || !(*st)->next || !(*st)->next->next)
		return ;
	max_idx = get_max_indx(*st);
	if ((*st)->index == max_idx)
		ra(st, 1);
	else if ((*st)->next->index == max_idx)
		rra(st, 1);
	if ((*st)->index > (*st)->next->index)
		sa(st, 1);
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

int	search_min_pos(t_stack *stack)
{
	int	min_pos;
	int	min_index;

	min_pos = 0;
	min_index = stack->index;
	while (stack)
	{
		if (stack->index <= min_index)
		{
			min_index = (stack)->index;
			min_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (min_pos);
}
