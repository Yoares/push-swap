#include "linked.h"

t_list *addfront(t_list *list, t_list *new_node)
{
    if (!new_node)
        return list;
    new_node->next = list;
    return new_node;
}