#include "push_swap.h"

t_list *ft_lstnew(int node)
{
    t_list *new_node;
    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = node;
    new_node->next = NULL;
    return new_node;
}
