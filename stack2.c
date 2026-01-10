/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:17:27 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/09 20:25:53 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *MyStack)
{
	t_node	*temp;

	temp = pop(MyStack);
	while (temp)
	{
		free(temp);
		temp = pop(MyStack);
	}
	free(MyStack);
}
