#include "push_swap.h"

void	set_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	target_pos(t_stack **stack_a, int index, int targ_index, int tar_pos)
{
	t_stack *tmp;

	tmp = *stack_a;
	while(tmp)
	{
		if (targ_index > index && tmp->index < targ_index)
		{
			targ_index = tmp-index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
}

void	sorting_st(t_stack **stack_a, t_stack **stack_b)
{
	dev_stack(stack_a, stack_b);
	
}