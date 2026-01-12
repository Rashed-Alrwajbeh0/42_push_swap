#include "push_swap.h"

static int	order(t_node *top, int size)
{
	int	temp;

	if (size <= 1)
		return (1);
	while (size > 1)
	{
		temp = top->content;
		top = top->below;
		if (top->content > temp)
			return (0);
		size--;
	}
	return (1);
}

static int	find_max(t_stack *stack)
{
	t_node	*node;
	int		max;
	int		ans;
	int		idx;

	node = stack->top;
	max = node->content;
	ans = 1;
	idx = 1;
	while (idx <= stack->size)
	{
		if (node->content > max)
		{
			max = node->content;
			ans = idx;
		}
		node = node->below;
		idx++;
	}
	return (ans);
}

void	selection(t_stack *a, t_stack *b, t_counter *c)
{
	int	num;
	int	moves;

	while (b->size > 1)
	{
		num = find_max(b);
		if (num <= (b->size / 2) + (b->size % 2))
		{
			while (num-- > 1)
				rb(b, c);
		}
		else
		{
			moves = b->size - num + 1;
			while (moves-- > 0)
				rrb(b, c);
		}
		if (order(b->top, b->size))
			break ;
		pa(a, b, c);
	}
	while (b->size > 0)
		pa(a, b, c);
}
