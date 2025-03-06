/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:29:23 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:29:23 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*set_arr(t_stack *stack_a, int size)
{
	int	i;
	int	*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (stack_a)
	{
		arr[i++] = stack_a->data;
		stack_a = stack_a->next;
	}
	return (arr);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	swap;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - j - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
			}
			i++;
		}
		j++;
	}
}

void	get_index(t_stack **stack)
{
	int		*arr;
	int		i;
	int		size;
	t_stack	*tmp;

	size = lstsize(*stack);
	arr = set_arr(*stack, size);
	sort_arr(arr, size);
	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->data)
			{
				tmp->index = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

void	last_sort(t_stack **a)
{
	int	min_pos;
	int	size;

	set_position(a);
	size = lstsize(*a);
	min_pos = search_min_pos(*a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(a, 1);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(a, 1);
			min_pos--;
		}
	}
}

void	dev_stack(t_stack **stack_a, t_stack **stack_b)
{
	int (size), (mid), (pushed);
	get_index(stack_a);
	size = lstsize(*stack_a);
	pushed = 0;
	mid = size / 2;
	while (pushed < mid && size > 3)
	{
		if ((*stack_a)->index <= mid)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			ra(stack_a, 1);
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b, 1);
		pushed++;
	}
}
