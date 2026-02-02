/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:32:29 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 10:32:30 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	help_radix2(int idx, int j, t_node *head)
{
	t_node	*temp;

	temp = head;
	while (j)
	{
		temp = temp->below;
		j--;
	}
	return (temp->bin[idx]);
}
