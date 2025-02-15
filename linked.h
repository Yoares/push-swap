#ifndef LINKED
#define LINDED

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_list{
    int data;
    struct  t_list *next;
}t_list;

typedef struct Stack {
    t_list *head;
} Stack;

t_list *addfront(t_list *list, t_list *new_node);
t_list *addback(t_list *list, t_list *node);
t_list *ft_lstnew(int node);
void init_stack(Stack *stack);
void print_stack(Stack *stack);
#endif