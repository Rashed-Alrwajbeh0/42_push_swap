#include "push_swap.h"

int	min_down(t_stack *stack, int *val, int chunck_size)
{
	t_node	*node;
	int		idx;

	node = stack->bottom;
	*val = node->content;
	idx = stack->size;
	while (idx > 0)
	{
		if (node->content < chunck_size)
		{
			*val = node->content;
			return (idx);
		}
		node = node->above;
		idx--;
	}
	return (-1);
}

int	min_up(t_stack *stack, int *val, int chunck_size)
{
	t_node	*node;
	int		idx;

	node = stack->top;
	*val = node->content;
	idx = 1;
	while (idx <= stack->size)
	{
		if (node->content < chunck_size)
		{
			*val = node->content;
			return (idx);
		}
		node = node->below;
		idx++;
	}
	return (-1);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void	switch_stack_content(t_stack *mystack, int *sorted_arr)
{
	int		j;
	int		i;
	t_node	*node;

	j = -1;
	node = mystack->top;
	while (++j < mystack->size)
	{
		i = -1;
		while (++i < mystack->size)
		{
			if (node->content == sorted_arr[i])
			{
				node->content = i;
				break ;
			}
		}
		node = node->below;
	}
}

void	return_stack(t_stack *mystack, int *sorted_nums)
{
	t_node	*mynode;
	int		idx;

	mynode = mystack->top;
	idx = -1;
	while (++idx < mystack->size)
	{
		mynode->content = sorted_nums[mynode->content];
		mynode = mynode->below;
	}
}
