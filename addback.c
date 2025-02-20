#include "push_swap.h"

void    addback(t_stack **list, t_stack *node)
{
    t_stack *tmp;

    if (!node)
        return;
    if (*list == NULL)
    {
        *list = node;
        return ;
    }
    tmp = *list;
    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
    node->next = NULL;

}