/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:03:01 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 14:21:04 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	han_c(va_list list)
{
	ft_putchar_fd((char)va_arg(list, int), 1);
	return (1);
}

int	han_s(va_list list)
{
	char	*sub;

	sub = va_arg(list, char *);
	ft_putstr_fd(sub, 1);
	if (!sub)
		return (6);
	return (ft_strlen(sub));
}

int	han_di(va_list list)
{
	return (put_int(va_arg(list, int)));
}

int	han_u(va_list list)
{
	return (put_uint(va_arg(list, unsigned int)));
}
