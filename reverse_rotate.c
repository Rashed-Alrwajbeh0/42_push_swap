/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:11:00 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 13:25:35 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_counter *c)
{
	t_node	*old_bottom;

	if (c)
	{
		c->rra++;
		ft_printf("rra\n");
	}
	if (!stack_a || !stack_a->top || stack_a->size <= 1)
		return ;
	old_bottom = stack_a->bottom;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = old_bottom->above;
}

void	rrb(t_stack *stack_b, t_counter *c)
{
	t_node	*old_bottom;

	if (c)
	{
		c->rrb++;
		ft_printf("rrb\n");
	}
	if (!stack_b || !stack_b->top || stack_b->size <= 1)
		return ;
	old_bottom = stack_b->bottom;
	stack_b->top = stack_b->bottom;
	stack_b->bottom = old_bottom->above;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	rrb(stack_b, NULL);
	rra(stack_a, NULL);
	c->rrr++;
	ft_printf("rrr\n");
}
