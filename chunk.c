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

void	shift_to_b(t_stack *a, t_stack *b, t_counter *c, int end)
{
	int	start;

	start = 0;
	while (a->size)
	{
		if (a->top->content <= start)
		{
			pb(a, b, c);
			start++;
			end++;
		}
		else if (a->top->content > start && a->top->content <= end)
		{
			pb(a, b, c);
			rb(b, c);
			start++;
			end++;
		}
		else
			ra(a, c);
	}
}

int	chunk_sort(t_stack *a, t_stack *b, t_counter *c)
{
	int	size;
	int	*array_nums;

	if (a->size <= 3)
		return (selection_three(a, c), 1);
	if (a->size <= 100)
		size = 20;
	else
		size = 40;
	array_nums = indexing(a);
	if (!array_nums)
		return (0);
	shift_to_b(a, b, c, size);
	selection(a, b, c);
	return (return_stack(a, array_nums), free(array_nums), 1);
}
