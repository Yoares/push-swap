#include "linked.h"

t_list *rotate(Stack *stack)
{
    t_list *tmp;

    tmp = stack->head;
    addback(stack, tmp);
    free(tmp);
    return stack;
}

int main()
{
    Stack *stack;
    init_stack(stack);
    addfront(stack, 4);
    addfront(stack, 3);
    addfront(stack, 2);
    addfront(stack, 1);
    print_stack(stack);
}