#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				value;
	int             index;
	struct s_stack	*next;
}					t_stack;

void    addfront(t_stack **list, t_stack *new_node);
void    addback(t_stack **list, t_stack *node);
int     lstsize(t_stack *stack);
t_stack  *lstnew(int node);

// op func
void    push_stack(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack);
void    rb(t_stack **stack);
void    sa(t_stack **stack);
void	rra(t_stack **stack);
void 	pa(t_stack **stack_a, t_stack **stack_b);
void 	pb(t_stack **stack_a, t_stack **stack_b);

// sort function
void    sort_three(t_stack **stack);
void    sort_five(t_stack **stack_a, t_stack **stack_b);
int     search_min_num(t_stack *stack);
int 	is_sorted(t_stack *stack);
void	remove_node(t_stack **stack, int data);
// parcing func
int     parc_args(int ac, char **av, t_stack **stack_a);

//error handeling
void	free_stack(t_stack **stack);
void	error_exit(t_stack **stack_a, t_stack **stack_b);
void 	free_split(char **split);

// range algho

#endif
