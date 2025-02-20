#include "push_swap.h"

static void	error_exit(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;

	if (!parc_args(ac, av, &stack_a))
		error_exit(&stack_a, &stack_b);
}