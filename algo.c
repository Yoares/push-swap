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

void	dev_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	int (i), (size), (dev), (pushed);
	i = 0;
	size = lstsize(*stack_a);
	tmp = *stack_a;
	pushed = 0;
	get_index(stack_a);
	dev = size / 2;
	while (i < size - 1 && pushed < size / 2 && tmp)
	{
		if (tmp->index <= dev)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if (tmp->index > dev)
			ra(stack_a, 1);
		tmp = tmp->next;
		i++;
	}
	size = lstsize(*stack_a);
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
	print_stack(*stack_a);
	print_stack(*stack_b);
}
