/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:07:11 by klafi             #+#    #+#             */
/*   Updated: 2026/01/11 12:32:43 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_node *top, int size)
{
	int	temp;

	if (size <= 1)
		return (1);
	while (size > 1)
	{
		temp = top->content;
		top = top->below;
		if (top->content < temp)
			return (0);
		size--;
	}
	return (1);
}

static int	find_min(t_stack *stack)
{
	t_node	*node;
	int		min;
	int		ans;
	int		idx;

	node = stack->top;
	min = node->content;
	ans = 1;
	idx = 1;
	while (idx <= stack->size)
	{
		if (node->content < min)
		{
			min = node->content;
			ans = idx;
		}
		node = node->below;
		idx++;
	}
	return (ans);
}

void	selection_sort(t_stack *a, t_stack *b, t_counter *c)
{
	int	num;
	int	moves;

	while (a->size > 1)
	{
		num = find_min(a);
		if (num <= (a->size / 2) + (a->size % 2))
			while (num-- > 1)
				ra(a, c);
		else
		{
			moves = a->size - num + 1;
			while (moves-- > 0)
				rra(a, c);
		}
		if (check_order(a->top, a->size))
			break ;
		pb(a, b, c);
	}
	while (b->size > 0)
		pa(a, b, c);
}
