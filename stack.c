/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:29:21 by klafi             #+#    #+#             */
/*   Updated: 2026/01/09 21:10:54 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

t_stack	*init_stack(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return stack;
}

void	push(t_stack *stack, int elem)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->above = new_node;
	new_node->below = new_node;
	new_node->content = elem;
	if (stack->top)
		new_node->below = stack->top;
	stack->top = new_node;
	if (stack->bottom)
		new_node->above = stack->bottom;
	else
		stack->bottom = new_node;
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*top_node;

	if (!stack || !stack->top)
		return (NULL);
	top_node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else if (stack->size > 1)
	{
		stack->top = top_node->below;
		stack->top->above = stack->bottom;
		top_node->below = NULL;
		top_node->above = NULL;
	}
	stack->size--;
	return (top_node);
}

void	visualize(t_stack *stack)
{
	t_node	*node;

	if (!stack)
	{
		ft_printf("Stack is NULL\n");
		return ;
	}
	else if (!stack->top)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	ft_printf("top -> %d", stack->top->content);
	node = stack->top->below;
	while (node != stack->top && node)
	{
		ft_printf(" -> %d", node->content);
		node = node->below;
	}
	ft_printf("\n");
}

t_counter	*init_counter(void)
{
	t_counter *counter;

	counter = malloc(sizeof(t_counter));
	counter->sa = 0;
	counter->sb = 0;
	counter->ss = 0;
	counter->pa = 0;
	counter->pb = 0;
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
	return (counter);
}
int main(void)
{
	t_stack *stack = init_stack();
	t_counter *counter = init_counter();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	pop(stack);
	push(stack, 4);
	visualize(stack);
	pop(stack);
	pop(stack);
	ft_printf("stack's head : %d  stack's bottom : %d\n", stack->top->content, stack->bottom->content);
	visualize(stack);
	return (0);
}
