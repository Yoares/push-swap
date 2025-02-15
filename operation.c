#include "linked.h"

void init_stack(Stack *stack)
{
    stack->head = NULL;
}

int isempty(Stack *stack)
{
    return (stack->head == NULL);
}

void push(Stack *stack, int new_data)
{
    t_list *new_node;

    new_node = ft_lstnew(new_data);
    if (!new_node) 
        return;
    new_node->next = stack->head;
    stack->head = new_data;
}

void remove_top(Stack *stack)
{
    t_list *tmp;

    if (isempty(stack))
        return;
    else
        tmp->next = stack->head;
        stack->head = stack->head->next;
    free(tmp);
}

void print_stack(Stack *stack) {
    t_list *current = stack->head;
    printf("Stack: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

