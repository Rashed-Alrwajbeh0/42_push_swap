/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:25:19 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 14:21:23 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "push_swap.h"

int	gen_str(const char *s, int idx, va_list list, int len)
{
	if (*(s + idx) == 'c')
		len += han_c(list);
	else if (*(s + idx) == 's')
		len += han_s(list);
	else if (*(s + idx) == 'd' || *(s + idx) == 'i')
		len += han_di(list);
	else if (*(s + idx) == 'u')
		len += han_u(list);
	else if (*(s + idx) == '%')
		len += han_mod();
	else if (*(s + idx) == 'f')
		len += han_f(list);
	else
	{
		write(1, s + idx - 1, 2);
		len += 2;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		idx;
	int		len;

	if (!s)
		return (-1);
	va_start(list, s);
	idx = 0;
	len = 0;
	while (*(s + idx))
	{
		if (*(s + idx) == '%')
			len = gen_str(s, ++idx, list, len);
		else
		{
			write(1, s + idx, 1);
			++len;
		}
		idx++;
	}
	va_end(list);
	return (len);
}
