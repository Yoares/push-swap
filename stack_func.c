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

int lstsize(t_stack *stack)
{
    int i;
    t_stack *tmp;

    tmp = stack;
    i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void	addfront(t_stack **list, t_stack *new_node)
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