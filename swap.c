/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:18:59 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 12:41:43 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, t_counter *c)
{
	t_node	*a;
	t_node	*b;

	if (c)
	{
		c->sa++;
		ft_printf("sa\n");
	}
	if (stack_a->size <= 1 || !stack_a)
		return ;
	a = stack_a->top;
	b = a->below;
	if (stack_a->size == 2)
	{
		stack_a->top = b;
		stack_a->bottom = a;
		return ;
	}
	b->below->above = a;
	a->above = b;
	a->below = b->below;
	b->below = a;
	b->above = stack_a->bottom;
	stack_a->top = b;
	stack_a->bottom->below = b;
}

void	sb(t_stack *stack_b, t_counter *c)
{
	t_node	*b;
	t_node	*a;

	if (c)
	{
		c->sb++;
		ft_printf("sb\n");
	}
	if (stack_b->size <= 1 || !stack_b)
		return ;
	a = stack_b->top;
	b = a->below;
	if (stack_b->size == 2)
	{
		stack_b->top = b;
		stack_b->bottom = a;
		return ;
	}
	b->below->above = a;
	a->above = b;
	a->below = b->below;
	b->below = a;
	b->above = stack_b->bottom;
	stack_b->top = b;
	stack_b->bottom->below = b;
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	sa(stack_a, NULL);
	sb(stack_b, NULL);
	c->ss++;
	ft_printf("ss\n");
}
