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

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
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

void sheft_stack(t_stack **stack_a)
{
	int min_pos;

	min_pos = search_min_pos(*stack_a);
	if (min_pos > lstsize(*stack_a) / 2)
	{
		min_pos -= lstsize(*stack_a) / 2+ 1 ;
		while (min_pos > 0)
		{
			rra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
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
	mid = size  / 2  - 1  ;
	while (pushed < mid && size < 3 )
	{
		if ((*stack_a)->index <= mid)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if ((*stack_a)->index > mid)
			ra(stack_a, 1);	
		size = lstsize(*stack_a);
	}
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size = lstsize(*stack_a);
	}
	
}
