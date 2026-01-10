/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:11:11 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 09:54:59 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	han_x(va_list list)
{
	return (put_hex(va_arg(list, unsigned int)));
}

int	han_xcap(va_list list)
{
	return (put_hex_cap(va_arg(list, unsigned int)));
}

int	han_mod(void)
{
	write(1, "%", 1);
	return (1);
}
