/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:17:27 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/27 19:17:10 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	temp = pop(stack);
	while (temp)
	{
		free(temp->bin);
		free(temp);
		temp = pop(stack);
	}
	free(stack);
}
