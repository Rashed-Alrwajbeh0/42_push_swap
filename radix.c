/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:49:31 by klafi             #+#    #+#             */
/*   Updated: 2026/01/27 20:15:09 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int num)
{
	int	ans;

	ans = 0;
	while (num)
	{
		ans++;
		num /= 2;
	}
	return (ans);
}

char	*convert_to_binary(int num, int idx)
{
	char	*ans;

	ans = malloc(idx + 1);
	if (!ans)
		return (NULL);
	ans[idx--] = '\0';
	if (num == 0)
		ans[idx] = '0';
	while (num > 0)
	{
		if (num % 2)
			ans[idx] = '1';
		else
			ans[idx] = '0';
		idx--;
		num /= 2;
	}
	while (idx >= 0)
	{
		ans[idx] = '0';
		idx--;
	}
	return (ans);
}

int	convert_stack_to_binary(t_stack *mystack)
{
	t_node	*temp;
	int		i;
	char	*j;
	int		k;

	temp = mystack->top;
	i = 0;
	k = max(mystack->size);
	while (i < mystack->size)
	{
		j = convert_to_binary(temp->content, k);
		if (!j)
			return (-1);
		temp->bin = j;
		temp = temp->below;
		i++;
	}
	return (k);
}

void	help_radix(t_stack *a, t_stack *b, t_counter *c, int idx)
{
	int	i;
	int	k;
	int	j;

	i = a->size;
	while (i > 0)
	{
		if (a->top->bin[idx] == '0')
			pb(a, b, c);
		else
			ra(a, c);
		i--;
	}
	k = b->size;
	j = 0;
	while (k)
	{
		if ((idx > 0 && help_radix2(idx - 1, j, b->top) == '1') || idx == 0)
			pa(a, b, c);
		else
			j++;
		k--;
	}
}

int	radix(t_stack *a, t_stack *b, t_counter *c)
{
	int	*nums;
	int	j;

	nums = indexing(a);
	if (!nums)
		return (0);
	j = convert_stack_to_binary(a);
	if (!j)
		return (0);
	j--;
	while (j != -1)
	{
		help_radix(a, b, c, j);
		if (check_order(a->top, a->size))
			return (selection(a, b, c), free(nums), 1);
		j--;
	}
	return (return_stack(a, nums), free(nums), 1);
}
