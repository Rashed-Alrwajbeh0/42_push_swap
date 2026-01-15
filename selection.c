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

	if (size <= 1)
		return (1);
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

static int	find_min(t_stack *stack)
{
	t_node	*node;
	int		min;
	int		ans;
	int		idx;

	node = stack->top;
	min = node->content;
	ans = 1;
	idx = 1;
	while (idx <= stack->size)
	{
		if (node->content < min)
		{
			min = node->content;
			ans = idx;
		}
		node = node->below;
		idx++;
	}
	return (ans);
}

void	selection_three(t_stack *a, t_counter *c)
{
	int	first;
	int	second;
	int	third;

	first = a->top->content;
	second = a->top->below->content;
	third = a->bottom->content;
	if (a->size == 2 && a->top->content > a->top->below->content)
		sa(a, c);
	else if (first < second && second > third && first < third)
	{
		sa(a, c);
		ra(a, c);
	}
	else if (first < second && second > third && first > third)
		rra(a, c);
	else if (first > second && second < third && first < third)
		sa(a, c);
	else if (first > second && second < third && first > third)
		ra(a, c);
	else if (first > second && second > third)
	{
		sa(a, c);
		rra(a, c);
	}
}

void	selection_sort(t_stack *a, t_stack *b, t_counter *c)
{
	int	num;
	int	moves;

	while (a->size > 3)
	{
		num = find_min(a);
		if (num <= (a->size / 2) + (a->size % 2))
			while (num-- > 1)
				ra(a, c);
		else
		{
			moves = a->size - num + 1;
			while (moves-- > 0)
				rra(a, c);
		}
		if (check_order(a->top, a->size))
			break ;
		pb(a, b, c);
	}
	if (a->size > 1 && !check_order(a->top, a->size))
		selection_three(a, c);
	while (b->size > 0)
		pa(a, b, c);
}
