#include "push_swap.h"

int	set_array(t_stack *stack_a)
{
	int	i;
	int *arr;
	i = 0;
	while (stack_a)
	{
		arr[i++] = stack_a->data;
		stack_a = stack_a->next;
	}
}

void	swap(int *x, int *y)
{
	int *tmp;

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
			{
				swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int	get_index(t_stack **stack)
{
	int *arr;
	int	i;
	int size;
	t_stack *tmp;

	size = lstsize(*stack);
	arr = set_array(stack);
	tmp = *stack;

	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->data)
			{
				tmp->index = i + 1;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}
