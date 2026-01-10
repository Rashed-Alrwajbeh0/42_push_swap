/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:11:00 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 11:03:25 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_counter *c)
{
	t_node	*old_bottom;

	c->rra++;
	ft_printf("rra\n");
	old_bottom = stack_a->bottom;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = old_bottom->above;
}

void	rrb(t_stack *stack_b, t_counter *c)
{
	t_node	*old_bottom;

	c->rrb++;
	ft_printf("rrb\n");
	old_bottom = stack_b->bottom;
	stack_b->top = stack_b->bottom;
	stack_b->bottom = old_bottom->above;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	rrb(stack_b, c);
	rra(stack_a, c);
	c->rra--;
	c->rrb--;
	c->rrr++;
	ft_printf("rrr\n");
}
