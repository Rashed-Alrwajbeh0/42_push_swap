/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 07:38:23 by klafi             #+#    #+#             */
/*   Updated: 2026/01/15 10:29:02 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*indexing(t_stack *mystack)
{
	int		*nums;
	int		i;
	t_node	*mynode;

	nums = malloc(mystack->size * sizeof(int));
	if (!nums)
		return (NULL);
	mynode = mystack->top;
	i = 0;
	while (i < mystack->size)
	{
		nums[i] = mynode->content;
		mynode = mynode->below;
		i++;
	}
	sort_array(nums, mystack->size);
	switch_stack_content(mystack, nums);
	return (nums);
}

void	chunk_helper(int num1, int num2, t_stack *a, t_counter *c)
{
	if (num1 <= num2)
	{
		while (num1 > 0)
		{
			ra(a, c);
			num1--;
		}
	}
	else
	{
		while (num2 > 0)
		{
			rra(a, c);
			num2--;
		}
	}
}

static void	help(t_stack *a, t_stack *b, t_counter *c, int chunk_size)
{
	int	val1;
	int	val2;
	int	idx1;
	int	idx2;

	if (a->size == 3 && !b->size)
		selection_three(a, c);
	else
	{
		while (a->size > 0)
		{
			idx1 = min_up(a, &val1, chunk_size);
			idx2 = min_down(a, &val2, chunk_size);
			if (idx1 == -1 && idx2 == -1)
			{
				chunk_size += 40;
				continue ;
			}
			chunk_helper(idx1 - 1, a->size - idx2 + 1, a, c);
			pb(a, b, c);
		}
		selection(a, b, c);
	}
}

int	chunk_sort(t_stack *a, t_stack *b, t_counter *c, int chunk_size)
{
	int	val1;
	int	val2;
	int	idx1;
	int	idx2;
	int	*array_nums;

	array_nums = indexing(a);
	if (!array_nums)
		return (0);
	if (check_order(a->top, a->size))
		return (return_stack (a, array_nums), free(array_nums), 1);
	while (a->size > 3)
	{
		idx1 = min_up(a, &val1, chunk_size);
		idx2 = min_down(a, &val2, chunk_size);
		if (idx1 == -1 && idx2 == -1)
		{
			chunk_size += 40;
			continue ;
		}
		chunk_helper(idx1 - 1, a->size - idx2 + 1, a, c);
		pb(a, b, c);
	}
	help(a, b, c, chunk_size);
	return (return_stack (a, array_nums), free(array_nums), 1);
}
