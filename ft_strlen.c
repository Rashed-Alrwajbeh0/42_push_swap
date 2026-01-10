/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:28:35 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 09:54:34 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_strlen(const char *s)
{
	int	counter;
	int	index;

	counter = 0;
	index = 0;
	while (*(s + index) != 0)
	{
		counter++;
		index++;
	}
	return (counter);
}
