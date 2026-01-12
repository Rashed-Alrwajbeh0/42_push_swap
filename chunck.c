#include "push_swap.h"

int	*indexing(t_stack *mystack)
{
	int		*nums;
	int		i;
	t_node	*mynode;

	nums = malloc(mystack->size * sizeof(int));
	if (!nums)
		return (NULL);
	mynode = mystack->top;
	i = 0;
	while (i < mystack->size)
	{
		nums[i] = mynode->content;
		mynode = mynode->below;
		i++;
	}
	sort_array(nums, mystack->size);
	switch_stack_content(mystack, nums);
	return (nums);
}

void	chunck_helper(int num1, int num2, t_stack *a, t_counter *c)
{
	if (num1 <= num2)
	{
		while (num1 > 0)
		{
			ra(a, c);
			num1--;
		}
	}
	else
	{
		while (num2 > 0)
		{
			rra(a, c);
			num2--;
		}
	}
}

int	chunck_sort(t_stack *a, t_stack *b, t_counter *c, int chunck_size)
{
	int	val1;
	int	val2;
	int	idx1;
	int	idx2;
	int	*array_nums;

	array_nums = indexing(a);
	if (!array_nums)
		return (0);
	while (a->size > 0)
	{
		idx1 = min_up(a, &val1, chunck_size);
		idx2 = min_down(a, &val2, chunck_size);
		if (idx1 == -1 && idx2 == -1)
		{
			chunck_size += 40;
			continue ;
		}
		chunck_helper(idx1 - 1, a->size - idx2 + 1, a, c);
		pb(a, b, c);
	}
	selection(a, b, c);
	return (return_stack (a, array_nums), free(array_nums), 1);
}
