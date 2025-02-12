#include "linked.h"

t_list *addback(t_list *list, t_list *node)
{
    t_list *tmp;
    tmp = list;

    if (!node)
    {
        return list;
    }
    while(tmp)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
    return list;
}