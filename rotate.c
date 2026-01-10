/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:01:18 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 12:57:58 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, t_counter *c)
{
	t_node	*old_top;

	if (c)
	{
		c->ra++;
		ft_printf("ra\n");
	}
	if (!stack_a || !stack_a->top || stack_a->size <= 1)
		return ;
	old_top = stack_a->top;
	stack_a->top = stack_a->top->below;
	stack_a->bottom = old_top;
}

void	rb(t_stack *stack_b, t_counter *c)
{
	t_node	*old_top;

	if (c)
	{
		c->rb++;
		ft_printf("rb\n");
	}
	if (!stack_b || !stack_b->top || stack_b->size <= 1)
		return ;
	old_top = stack_b->top;
	stack_b->top = stack_b->top->below;
	stack_b->bottom = old_top;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	ra(stack_a, NULL);
	rb(stack_b, NULL);
	c->rr++;
	ft_printf("rr\n");
}
