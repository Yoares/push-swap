#include "linked.h"

void rotate(t_list **stack)
{
    t_list *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    addback(stack, tmp);
}

void rev_rotate(t_list **stack)
{
    t_list *tmp1;
    t_list *tmp2;
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

void sa(t_list **stack)
{
    t_list  *first;
    t_list *last;

    if (!stack || !*stack || !(*stack)->next)
        return; 
    first = *stack;
    last =  first->next;

    first->next = last->next;
    last->next = first;
    *stack = last;
}

void push_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

  if (!stack_a || !*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    addfront(stack_b, tmp);
}

void print(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", stack->data);
        stack = stack->next;
    }
}

int ft_lstsize(t_list *stack)
{
    int i;
    t_list *tmp;

    tmp = stack;
    i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void sort_three(t_list **stack)
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

void sort_five(t_list **stack_a, t_list **stack_b)
{
    while (ft_lstsize(stack_a) > 3)
    {
        
    }
    
}
int main()
{
    t_list *stack_a;
    stack_a = NULL;
//     addfront(&stack_a, ft_lstnew(6));
    addfront(&stack_a, ft_lstnew(5));
    addfront(&stack_a, ft_lstnew(4));
    addfront(&stack_a, ft_lstnew(1));
    addfront(&stack_a, ft_lstnew(3));
    addfront(&stack_a, ft_lstnew(2));
    printf("%s\n", "before");
    print(stack_a);
    t_list *stack_b;
    stack_b = NULL;
    printf("%s\n", "after sort");
    sort_five(&stack_a, &stack_b);
    print(stack_a);
}