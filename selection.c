/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:07:11 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 19:36:28 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min(t_stack *stack)
{
	t_node	*node;
	int		min;

	node = stack->top->below;
	min = node->content;
	while (node != stack->top)
	{
		if (node->content < min)
			min = node->content;
		node = node->below;
	}
	return (min);
}

void	selection_sort(t_stack *a, t_stack *b, t_counter *c)
{
	int	min;

	while (a->size)
	{
		min = find_min(a);
		while (a->top->content != min)
			ra(a, c);
		pb(a, b, c);
	}
	while (b->size)
		pa(a, b, c);
}
