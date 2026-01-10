/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:17:27 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 13:37:16 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	temp = pop(stack);
	while (temp)
	{
		free(temp);
		temp = pop(stack);
	}
	free(stack);
}
