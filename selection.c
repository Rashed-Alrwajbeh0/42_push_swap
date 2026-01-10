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

int	check_order(t_node *head, int size)
{
	int	temp;

	while (size > 1)
	{
		temp = head->content;
		head = head->below;
		if (head->content < temp)
			return (0);
		size--;
	}
	return (1);
}

static int find_min(t_stack *stack)
{
	t_node	*node;
	int		min;
	int		i;
	int		ans;

	node = stack->top;
	min = node->content;
	i = 1;
	ans = i;
	while (node != stack->bottom)
	{
		if (node->content < min)
		{
			min = node->content;
			ans = i;
		}
		i++;	
		node = node->below;
	}
	if (node->content < min)
	{
		min = node->content;
		ans = i;
	}
	return (ans);
}

void	selection_sort(t_stack *a, t_stack *b, t_counter *c, int size)
{
	int	num;
	int	i;
	int	y;

	while (1)
	{
		num = find_min(a);
		i = 1;
		if (num < size / 2)
		{
			while (i < num)
			{
				ra(a, c);
				i++;
			}
			if (!check_order(a->top, a->size))
				pb(a, b, c);
			else
				break ; 
		}
		else
		{
			while (i <= size - num)
			{
				rra(a, c);
				i++;
			}
			if (!check_order(a->top, a->size))
				pb(a, b, c);
			else
				break ; 
		}
	}
	if (b->size)
	{
		y = b->size;
		while (y > 0)
		{
			pa(a, b, c);
			y--;
		}
	}
}

