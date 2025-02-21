#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (ac < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;

    if (!parc_args(ac, av, &stack_a))
        error_exit(&stack_a, &stack_b);
    int size = lstsize(stack_a);
    if (size <= 3)
        sort_three(&stack_a);
    else if (size <= 5)
        sort_five(&stack_a, &stack_b);
    else
        range_sort(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}