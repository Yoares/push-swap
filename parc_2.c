/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:29:50 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:29:50 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	valid_num(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	check_duplicat(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static	int	set_stack_a(char **vals, t_stack **stack_a)
{
	long	value;
	t_stack	*new;
	int		i;

	i = 0;
	while (vals[i] != NULL)
	{
		if (valid_num(vals[i]))
		{
			value = ft_atoi(vals[i]);
			if (value > INT_MAX || value < INT_MIN)
				return (0);
			if (!check_duplicat(*stack_a, (int)value))
			{
				new = lstnew((int)value);
				if (!new)
					return (0);
				addback(stack_a, new);
			}
			else
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	parc_args(int ac, char **av, t_stack **stack_a)
{
	int		i;
	char	**vals;

	i = 1;
	while (i < ac)
	{
		vals = ft_split(av[i], ' ');
		if (!vals)
		{
			free_split(vals);
			error_exit(stack_a, NULL);
		}
		if (!set_stack_a(vals, stack_a))
			error_exit(stack_a, NULL);
		free_split(vals);
		i++;
	}
	return (1);
}
