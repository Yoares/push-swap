#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    addback(stack, tmp);
}

void rev_rotate(t_stack **stack)
{
    t_stack *tmp1;
    t_stack *tmp2;
    if (!stack || !*stack || !(*stack)->next)
        return; 
    tmp1 = *stack;
    while (tmp1->next->next)
    {
        tmp1 = tmp1->next;
    }
    tmp2 = tmp1->next;
    tmp1->next =  NULL;
    addfront(stack, tmp2);
}

void sa(t_stack **stack)
{
    t_stack  *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return; 
    first = *stack;
    last =  first->next;

    first->next = last->next;
    last->next = first;
    *stack = last;
}

void push_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

  if (!stack_a || !*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    addfront(stack_b, tmp);
}

// void print(t_stack *stack)
// {
//     while (stack)
//     {
//         printf("%d\n", stack->data);
//         stack = stack->next;
//     }
// }

int lstsize(t_stack *stack)
{
    int i;
    t_stack *tmp;

    tmp = stack;
    i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void sort_three(t_stack **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->data;
    b = (*stack)->next->data;
    c = (*stack)->next->next->data;

    if (a > b && a > c)
    {
        rotate(stack);
    }
    else if (b > a && b > c)
    {
        // rotate(stack);
        // rotate(stack);
        rev_rotate(stack);
    }

    a = (*stack)->data;
    b = (*stack)->next->data;

    if (a > b)
        sa(stack);
}

int search_min_num(t_stack *stack)
{
    int min;
    
    min = stack->data;
    while (stack)
    {
        if (stack->data < min)
        {
            min = (stack)->data;
        }
        stack = stack->next;    
    }
    return (min);
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int min;

    while (lstsize(*stack_a) > 3)
    {
        min = search_min_num(*stack_a);
        while (((*stack_a)->data) != min)
        {
            rev_rotate(stack_a);
        }
        push_stack(stack_a, stack_b);
    }
    sort_three(stack_a);
    push_stack(stack_b, stack_a);
    push_stack(stack_b, stack_a);
}
