#include "push_swap.h"

t_stack *lstnew(int node)
{
    t_stack *new_node;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    new_node->data = node;
    new_node->next = NULL;
    return new_node;
}
