#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct t_list{
    int data;
    struct  t_list *next;
}t_list;

// typedef struct s_stack
// {
// 	int				value;
// 	int				indx;
// 	int				pos;
// 	int				targ_pos;
// 	int				cost_a;
// 	int				cost_b;
// 	struct s_stack	*next;
// }					t_stack;

void    addfront(t_list **list, t_list *new_node);
void    addback(t_list **list, t_list *node);
t_list  *ft_lstnew(int node);
void    push_stack(t_list **stack_a, t_list **stack_b);
void    rotate(t_list **stack);
int     parc_args(int ac, char **av, t_list **stack_a);
int     ft_lstsize(t_list *stack);
#endif
