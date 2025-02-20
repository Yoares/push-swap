#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct t_stack{
    int data;
    struct  t_stack *next;
}t_stack;

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

void    addfront(t_stack **list, t_stack *new_node);
void    addback(t_stack **list, t_stack *node);
t_stack  *lstnew(int node);
void    push_stack(t_stack **stack_a, t_stack **stack_b);
void    rotate(t_stack **stack);
int     parc_args(int ac, char **av, t_stack **stack_a);
// int     ft_lstsize(t_stack *stack);
#endif
