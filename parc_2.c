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

static int	check_duplicat(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while(stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	parc_args(int ac, char **av, t_stack **stack_a)
{
	int		i;
	long	num;
	t_stack	*new_node;

	i = 1;
	while(i < ac)
	{
		if (!valid_num(av[i]))
			return (0);
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (check_duplicat(*stack_a, (int)num))
			return (0);
		new_node = lstnew((int)num);
		if (!new_node)
			return (0);
		addback(stack_a, new_node);
		i++;
	}
	return (1);
}
