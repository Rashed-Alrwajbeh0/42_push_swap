/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_for_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:47:03 by klafi             #+#    #+#             */
/*   Updated: 2026/01/25 16:47:06 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	while (b->size)
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
		pa(a, b, c);
	}
}
