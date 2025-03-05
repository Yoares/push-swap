/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:29:42 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:29:42 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack, int mark)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	addback(stack, tmp);
	if (mark)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int mark)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	addback(stack, tmp);
	if (mark)
		write(1, "rb\n", 3);
}

void	rra(t_stack **stack, int mark)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = NULL;
	addfront(stack, tmp2);
	if (mark)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack, int mark)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = NULL;
	addfront(stack, tmp2);
	if (mark)
		write(1, "rrb\n", 4);
}

void	sa(t_stack **stack, int mark)
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
		write(1, "sa\n", 3);
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

void	rr(t_stack **stack_a, t_stack **stack_b, int mark)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (mark)
		write(1, "rr\n", 3);
}
