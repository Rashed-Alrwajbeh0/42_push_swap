/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:11:00 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 14:14:01 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_counter *c)
{
	t_node	*old_bottom;

	c->rra++;
	old_bottom = stack_a->bottom;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = old_bottom->above;
}

void	rrb(t_stack *stack_b, t_counter *c)
{
	t_node	*old_bottom;

	c->rrb++;
	old_bottom = stack_b->bottom;
	stack_b->top = stack_b->bottom;
	stack_b->bottom = old_bottom->above;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	c->rrr++;
	rrb(stack_b, c);
	rra(stack_a, c);
	c->rra--;
	c->rrb--;
}
