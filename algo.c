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

int	find_largest_index(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	max = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
		}
		tmp = tmp->next;
	}
	return (max);
}

void	dev_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*next;

	int (i), (size), (max_index), (dev);
	i = 0;
	size = lstsize(*stack_a);
	tmp = *stack_a;
	get_index(stack_a);
	max_index = find_largest_index(*stack_a);
	dev = max_index / 2;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->index <= dev)
			pb(stack_a, stack_b);
		else if (tmp->index > dev)
			ra(stack_a);
		else
			tmp = next;
	}
	while (size - i > 3)
	{
		pb(stack_a, stack_b);
		i++;
	}
}
