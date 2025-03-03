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

int	target_pos(t_stack **stack_a, int index, int targ_index, int tar_pos)
{
	t_stack *tmp;

	tmp = *stack_a;
	while(tmp)
	{
		if (tmp->index > index && tmp->index < targ_index)
		{
			targ_index = tmp->index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (targ_index != INT_MAX)
		return (tar_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < targ_index)
		{
			targ_index = tmp->index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tar_pos);
}

void	set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		targ_pos;

	tmp_b = *stack_b;
	set_position(stack_a);
	set_position(stack_b);
	targ_pos = 0;
	while (tmp_b)
	{
		targ_pos = target_pos(stack_a, tmp_b->index, INT_MAX, targ_pos);
		tmp_b->targ_pos = targ_pos;
		tmp_b = tmp_b->next;
	}
}
void	sorting_st(t_stack **stack_a, t_stack **stack_b)
{
	dev_stack(stack_a, stack_b);
	while (*stack_b)
	{
		set_target_position(stack_a, stack_b);
		set_cost(stack_a, stack_b);
		short_path(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sheft_stack(stack_a);
}