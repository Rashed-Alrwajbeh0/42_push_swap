/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_for_main.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:54:27 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/25 18:57:22 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_cmp(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = -1;
	while (str1[++i])
		if (str1[i] != str2[i])
			return (0);
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

int	is_duplicate(int size, t_node *top, int val)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		if (val == top->content)
			return (1);
		top = top->below;
		counter++;
	}
	return (0);
}

int	is_int(char *str, int start, int end)
{
	if (end - start > 10)
		return (0);
	while (start < end)
	{
		if (str[start] > '9' || str[start] < '0')
			return (0);
		start++;
	}
	return (1);
}

int	help_with_checker(char *str, int start, int end, t_stack *MyStack)
{
	long	temp;
	t_node	*temp_node;

	temp = string_to_int(str, start, end);
	if (temp == 2147483648 || is_duplicate(MyStack->size, MyStack->top, temp))
		return (free_stack(MyStack), free(str), 0);
	else
	{
		temp_node = malloc(sizeof(t_node));
		temp_node->content = temp;
		temp_node->number_in_binary = NULL;
		push(MyStack, temp_node);
	}
	return (1);
}
