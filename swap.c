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

#include "stack.h"

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

void	pa(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	t_node	*node;

	c->pa++;
	if (stack_b->size == 0)
		return ;
	node = pop(stack_b);
	push(stack_a, node->content);
	free(node);
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	t_node	*node;

	c->pb++;
	if (stack_a->size == 0)
		return ;
	node = pop(stack_a);
	push(stack_b, node->content);
	free(node);
}

void	ra(t_stack *stack_a, t_counter *c)
{
	t_node	*old_top;

	c->ra++;
	if (!stack_a || !stack_a->top)
		return ;
	old_top = stack_a->top;
	stack_a->top = stack_a->top->below;
	stack_a->bottom = old_top;
}

void	rb(t_stack *stack_b, t_counter *c)
{
	t_node	*old_top;

	c->rb++;
	if (!stack_b || !stack_b->top)
		return ;
	old_top = stack_b->top;
	stack_b->top = stack_b->top->below;
	stack_b->bottom = old_top;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_counter *c)
{
	c->rr++;
	ra(stack_a, c);
	rb(stack_b, c);
	c->ra--;
	c->rb--;
}

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

void	rrr(t_stack *stack_a, t_stack *stack-b, t_counter *c)
{
	c->rrr++;
	rrb(stack_b, c);
	rra(stack_a, c);
	c->rra--;
	c->rrb--;
}
