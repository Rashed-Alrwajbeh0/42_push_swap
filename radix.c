/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:49:31 by klafi             #+#    #+#             */
/*   Updated: 2026/01/25 18:58:36 by klafi            ###   ########.fr       */
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
		temp->number_in_binary = j;
		temp = temp->below;
		i++;
	}
	return (k);
}

void	help_radix(t_stack *a, t_stack *b, t_counter *c, int idx)
{
	int	i;

	i = a->size;
	while (i > 0)
	{
		if (a->top && a->top->number_in_binary[idx] == '0')
			pb(a, b, c);
		else
			ra(a, c);
		i--;
	}
	while (b->size)
		pa(a, b, c);
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
		j--;
	}
	return (free(nums), 1);
}
