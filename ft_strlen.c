/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:28:35 by klafi             #+#    #+#             */
/*   Updated: 2025/12/27 13:18:10 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
