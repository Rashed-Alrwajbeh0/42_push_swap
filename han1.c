/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:03:01 by klafi             #+#    #+#             */
/*   Updated: 2025/12/26 14:43:25 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	han_p(va_list list)
{
	unsigned long	add;
	void			*p;

	p = va_arg(list, void *);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		add = (unsigned long)p;
		write(1, "0x", 2);
		return (put_hex(add) + 2);
	}
}

int	han_di(va_list list)
{
	return (put_int(va_arg(list, int)));
}

int	han_u(va_list list)
{
	return (put_uint(va_arg(list, unsigned int)));
}
