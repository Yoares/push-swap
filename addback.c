#include "linked.h"

void    addback(t_list **list, t_list *node)
{
    t_list *tmp;

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