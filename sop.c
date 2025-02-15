#include "linked.h"

void rotate(t_list **stack)
{
    t_list *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    addback(stack, tmp);
}

void back_rotate(t_list **stack)
{
    t_list *tmp1;
    t_list *tmp2;
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

    first = *stack;
    last =  first->next;

    first->next = last->next;
    last->next = first;
    *stack = last;
}

void push_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

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

// int main()
// {
//     t_list *stack;
//     stack = NULL;
//     addfront(&stack, ft_lstnew(6));
//     addfront(&stack, ft_lstnew(5));
//     addfront(&stack, ft_lstnew(4));
//     addfront(&stack, ft_lstnew(3));
//     addfront(&stack, ft_lstnew(2));
//     addfront(&stack, ft_lstnew(1));
//     printf("%s\n", "before");
//     print(stack);
//     t_list *stack_1;
//     stack_1 = NULL;
//     // addfront(&stack_1, ft_lstnew(6));
//     // addfront(&stack_1, ft_lstnew(5));
//     // addfront(&stack_1, ft_lstnew(4));
//     // addfront(&stack_1, ft_lstnew(3));
//     // addfront(&stack_1, ft_lstnew(2));
//     // printf("%s\n", "after rotate");
//     // rotate(&stack);
//     // print(stack);
//     // printf("%s\n", "after back rotate");
//     // back_rotate(&stack);
//     // sa(&stack_1);
//     printf("%s\n", "after push to b");
//     push_stack(&stack, &stack_1);
//      print(stack);
//     printf("%s\n", "stack b");
//     print(stack_1);
// }