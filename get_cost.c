/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:36:58 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/01 15:02:44 by ykhoussi         ###   ########.fr       */
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

