/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:36:58 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/02 21:41:24 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
	t_stack *tmp;

	tmp = *stack_b;
	size_b = lstsize(*stack_b);
	size_a = lstsize(*stack_a);
	
	while (tmp)
	{
		if(tmp->pos > size_b / 2)
			tmp->tarif_b = -(size_b - tmp->pos);
		else
			tmp->tarif_b = tmp->pos;
		if (tmp->targ_pos > size_a / 2)
			tmp->tarif_a = -(size_a - tmp->targ_pos);
		else
			tmp->tarif_a = tmp->targ_pos;
	}
}

int	val_abs(int	nb)
{
	if (nb > 0)
		return (nb);
	return (-nb);
}

void	short_path(t_stack **stack_a, t_stack **stack_b)
{
	int	tarif_a;
	int	tarif_b;
	int	total_t;
	int	min;
	t_stack	*tmp;

	tarif_a = 0;
	tarif_b = 0;
	min = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		total_t = val_abs(tmp->tarif_a) + val_abs(tmp->tarif_b);
		if (total_t < min)
		{
			tarif_a = tmp->tarif_a;
			tarif_b = tmp->tarif_b;
			total_t = min;
		}
		tmp = tmp->next;
	}
	apply_rotation(stack_a, stack_b, &tarif_a, &tarif_b);
}

void	rotate_stack(t_stack **stack_a, t_stack **stack_b, int *tarif_a, int *tarif_b)
{
	while (*tarif_a < 0 && *tarif_b < 0)
	{
		rrr(stack_a, stack_b);
		(*tarif_a)++;
		(*tarif_b)++;
	}
	while (*tarif_a > 0 && *tarif_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*tarif_a)--;
		(*tarif_b)--;
	}
}
void	apply_rotation(t_stack **stack_a, t_stack **stack_b, int *tarif_a, int *tarif_b)
{
	rotate_stack(stack_a, stack_b, tarif_a, tarif_b);
	while (tarif_b < 0)
	{
		rrb(stack_b, 1);
		tarif_b++;
	}
	while (tarif_b > 0)
	{
		rb(stack_b, 1);
		tarif_b--;
	}
	while (tarif_a < 0)
	{
		rra(stack_a, 1);
		tarif_a++;
	}
	while (tarif_a > 0)
	{
		ra(stack_a, 1);
		tarif_a--;
	}
	pa(stack_a, stack_b, 1);
}