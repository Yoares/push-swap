/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:21 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:30:21 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addback(t_stack **list, t_stack *node)
{
	t_stack	*tmp;

	if (!node)
		return ;
	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
	node->next = NULL;
}

int	lstsize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	addfront(t_stack **list, t_stack *new_node)
{
	if (!new_node)
		return ;
	if (!(*list))
	{
		(*list) = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = (*list);
		(*list) = new_node;
	}
}

t_stack	*lstnew(int node)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = node;
	new_node->next = NULL;
	return (new_node);
}

void	remove_node(t_stack **stack, int data)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	if (tmp->data == data)
	{
		*stack = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp && tmp->data != data)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	prev->next = tmp->next;
	free(tmp);
}
