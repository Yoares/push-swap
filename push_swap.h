#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

// typedef struct t_stack{
//     int data;
//     struct  t_stack *next;
// }t_stack;

typedef struct s_stack
{
	int				value;
	int				data;
	int				pos;
	int				targ_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

void    addfront(t_stack **list, t_stack *new_node);
void    addback(t_stack **list, t_stack *node);
int     lstsize(t_stack *stack);
t_stack  *lstnew(int node);

// op func
void    push_stack(t_stack **stack_a, t_stack **stack_b);
void    rotate(t_stack **stack);
void    sa(t_stack **stack);
int     search_min_num(t_stack *stack);

// sort function
void    sort_three(t_stack **stack);
void    sort_five(t_stack **stack_a, t_stack **stack_b);

// print stack
void print(t_stack *stack);

// parcing func
int     parc_args(int ac, char **av, t_stack **stack_a);

//error handeling
void	free_stack(t_stack **stack);
void	error_exit(t_stack **stack_a, t_stack **stack_b);
#endif
