/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:55:07 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 13:59:03 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
