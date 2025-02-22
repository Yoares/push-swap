#include "push_swap.h"

int get_range(int size)
{
	if (size <= 100)
		return (size / 6);
	else if (size <= 500)
		return (size / 14);
	else
		return (size / 20);
}

