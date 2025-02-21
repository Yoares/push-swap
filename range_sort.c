#include "push_swap.h"

// Calculate the optimal range based on stack size
int get_range(int size)
{
	if (size <= 100)
		return (size / 6);
	else if (size <= 500)
		return (size / 14);
	else
		return (size / 20);
}

// Index the stack from 0 to stack_size - 1
void index_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *min;
    int     index;

    index = 0;
    while (index < lstsize(*stack))
    {
        current = *stack;
        min = NULL;
        while (current)
        {
            if (current->index == -1 && (!min || current->value < min->value))
                min = current;
            current = current->next;
        }
        if (min)
            min->index = index++;
    }
}

// Push numbers in the current range from stack_a to stack_b
void push_range(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
    int size;
    int pushed;

    size = lstsize(*stack_a);
    pushed = 0;
    while (size > 0 && pushed < (end - start))
    {
        if ((*stack_a)->index >= start && (*stack_a)->index < end)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a);
        size--;
    }
}

// Main range sort algorithm
void range_sort(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;
    int range;
    int start;
    int max_num;

    // Initialize all indexes to -1
    t_stack *temp = *stack_a;
    while (temp)
    {
        temp->index = -1;
        temp = temp->next;
    }

    // Index the stack
    index_stack(stack_a);
    
    stack_size = lstsize(*stack_a);
    range = get_range(stack_size);
    start = 0;

    // Push numbers to stack_b in ranges
    while (*stack_a)
    {
        push_range(stack_a, stack_b, start, start + range);
        start += range;
    }

    // Push back to stack_a in descending order
    max_num = stack_size - 1;
    while (*stack_b)
    {
        temp = *stack_b;
        while (temp)
        {
            if (temp->index == max_num)
            {
                while ((*stack_b)->index != max_num)
                    rb(stack_b);
                pa(stack_a, stack_b);
                max_num--;
                break;
            }
            temp = temp->next;
        }
    }
}