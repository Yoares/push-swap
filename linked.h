#ifndef LINKED
#define LINDED

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_list{
    int data;
    struct  t_list *next;
}t_list;

void addfront(t_list **list, t_list *new_node);
void addback(t_list **list, t_list *node);
t_list *ft_lstnew(int node);
void push_stack(t_list **stack_a, t_list **stack_b);
#endif