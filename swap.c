/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:18:59 by klafi             #+#    #+#             */
/*   Updated: 2026/01/09 21:13:53 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, t_counter *c)
{
	t_node	*b;
	t_node	*a;

	c->sa++;
	if (stack_a->size <= 1)
		return ;
	a = stack_a->top;
	b = a->below;
	b->above = stack_a->bottom;
	a->below = b->below;
	b->below = a;
	a->above = b;
}

void	sb(t_stack *stack_b, t_counter *c)
{
	t_node	*b;
	t_node	*a;

	c->sb++;
	if (stack_b->size <= 1)
		return ;
	a = stack_b->top;
	b = a->below;
	b->above = stack_b->bottom;
	a->below = b->below;
	b->below = a;
	a->above = b;
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	sa(stack_a, c);
	sb(stack_b, c);
	c->sa--;
	c->sb--;
	c->ss++;
}
