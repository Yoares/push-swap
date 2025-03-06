/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:06 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/02/28 15:30:06 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				tarif_a;
	int				tarif_b;
	int				targ_pos;
	int				pos;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	addfront(t_stack **list, t_stack *new_node);
void	addback(t_stack **list, t_stack *node);
int		lstsize(t_stack *stack);
t_stack	*lstnew(int node);

// op func
void	push_stack(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack, int mark);
void	rb(t_stack **stack, int mark);
void	sa(t_stack **stack, int mark);
void	rra(t_stack **stack, int mark);
void	rrb(t_stack **stack, int mark);
void	rrr(t_stack **stack_a, t_stack **stack_b, int mark);
void	pa(t_stack **stack_a, t_stack **stack_b, int mark);
void	pb(t_stack **stack_a, t_stack **stack_b, int mark);
void	rr(t_stack **stack_a, t_stack **stack_b, int mark);
void	sb(t_stack **stack, int mark);
void	ss(t_stack **a, t_stack **b, int mark);

// sort function
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int		search_min_num(t_stack *stack);
int		is_sorted(t_stack *stack);
void	remove_node(t_stack **stack, int data);
void	dev_stack(t_stack **stack_a, t_stack **stack_b);
void	get_index(t_stack **stack);
void	sort_arr(int *arr, int size);
int		*set_arr(t_stack *stack_a, int size);
void	set_position(t_stack **stack);
void	set_cost(t_stack **stack_a, t_stack **stack_b);
void	short_path(t_stack **stack_a, t_stack **stack_b);
void	apply_rotation(t_stack **stack_a, t_stack **stack_b,
			int *tarif_a, int *tarif_b);
void	set_target_position(t_stack **stack_a, t_stack **stack_b);
void	last_sort(t_stack **a);

// parcing func
int		parc_args(int ac, char **av, t_stack **stack_a);

// algo
void	sorting_st(t_stack **stack_a, t_stack **stack_b);
int		search_min_pos(t_stack *stack);

// error handeling
void	free_stack(t_stack **stack);
void	error_exit(t_stack **stack_a, t_stack **stack_b);
void	free_split(char **split);
void	pr_err(void);

#endif
