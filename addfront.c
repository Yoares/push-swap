#include "push_swap.h"

void addfront(t_stack **list, t_stack *new_node)
{
    if (!new_node)
        return ;
    if (!(*list))
        {
            (*list) = new_node;
            new_node->next = NULL; 
        }
    else
    {
        new_node->next =  (*list);
        (*list) = new_node;
    }
}