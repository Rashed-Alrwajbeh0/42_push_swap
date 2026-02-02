/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helper_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:47:54 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 10:31:39 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void	switch_stack_content(t_stack *mystack, int *sorted_arr)
{
	int		j;
	int		i;
	t_node	*node;

	j = -1;
	node = mystack->top;
	while (++j < mystack->size)
	{
		i = -1;
		while (++i < mystack->size)
		{
			if (node->content == sorted_arr[i])
			{
				node->content = i;
				break ;
			}
		}
		node = node->below;
	}
}

void	return_stack(t_stack *mystack, int *sorted_nums)
{
	t_node	*mynode;
	int		idx;

	mynode = mystack->top;
	idx = -1;
	while (++idx < mystack->size)
	{
		mynode->content = sorted_nums[mynode->content];
		mynode = mynode->below;
	}
}
