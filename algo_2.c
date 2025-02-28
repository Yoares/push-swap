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

void	sorting_st(t_stack **stack_a, t_stack **stack_b)
{
	dev_stack(stack_a, stack_b);
	
}