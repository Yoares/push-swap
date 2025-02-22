#include "push_swap.h"

void ra(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack || !(*stack)->next)
        return;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    addback(stack, tmp);
    write(1, "ra\n", 3);
}

void rb(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack || !(*stack)->next)
        return;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    addback(stack, tmp);
    write(1, "rb\n", 3);
}

void rra(t_stack **stack)
{
    t_stack *tmp1;
    t_stack *tmp2;
    
    if (!stack || !*stack || !(*stack)->next)
        return;
    tmp1 = *stack;
    while (tmp1->next->next)
        tmp1 = tmp1->next;
    tmp2 = tmp1->next;
    tmp1->next = NULL;
    addfront(stack, tmp2);
    write(1, "rra\n", 4);
}

void sa(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    last = first->next;
    first->next = last->next;
    last->next = first;
    *stack = last;
    write(1, "sa\n", 3);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!stack_b || !*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    addfront(stack_a, tmp);
    write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!stack_a || !*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    addfront(stack_b, tmp);
    write(1, "pb\n", 3);
}