#include "linked.h"

void addfront(t_list **list, t_list *new_node)
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