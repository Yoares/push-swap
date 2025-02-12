#ifndef LINKED
#define LINDED

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_list{
    void *data;
    struct  t_list *next;
}t_list;

t_list *addfront(t_list *list, t_list *new_node);
t_list *addback(t_list *list, t_list *node);
t_list *ft_lstnew(void* node);
#endif