/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:25:19 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 13:45:30 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf.h"

int	dig_num_hex(unsigned long dec)
{
	int	dig_num;

	dig_num = 1;
	while (dec / 16)
	{
		dig_num++;
		dec /= 16;
	}
	return (dig_num);
}

int	put_hex(unsigned long dec)
{
	int		dig;
	int		dig_num;
	char	*hex;

	dig_num = dig_num_hex(dec);
	hex = malloc(dig_num + 1);
	hex[dig_num] = 0;
	while (--dig_num >= 0)
	{
		dig = dec % 16;
		dec /= 16;
		if (dig >= 10)
			hex[dig_num] = 87 + dig;
		else
			hex[dig_num] = dig + '0';
	}
	ft_putstr_fd(hex, 1);
	dig = ft_strlen(hex);
	free(hex);
	return (dig);
}

int	put_hex_cap(unsigned long dec)
{
	int		dig;
	int		dig_num;
	char	*hex;

	dig_num = dig_num_hex(dec);
	hex = malloc(dig_num + 1);
	hex[dig_num] = 0;
	while (--dig_num >= 0)
	{
		dig = dec % 16;
		dec /= 16;
		if (dig >= 10)
			hex[dig_num] = 55 + dig;
		else
			hex[dig_num] = dig + '0';
	}
	ft_putstr_fd(hex, 1);
	dig = ft_strlen(hex);
	free(hex);
	return (dig);
}

int	gen_str(const char *s, int idx, va_list list, int len)
{
	if (*(s + idx) == 'c')
		len += han_c(list);
	else if (*(s + idx) == 's')
		len += han_s(list);
	else if (*(s + idx) == 'p')
		len += han_p(list);
	else if (*(s + idx) == 'd' || *(s + idx) == 'i')
		len += han_di(list);
	else if (*(s + idx) == 'u')
		len += han_u(list);
	else if (*(s + idx) == 'x')
		len += han_x(list);
	else if (*(s + idx) == 'X')
		len += han_xcap(list);
	else if (*(s + idx) == '%')
		len += han_mod();
 	else if(*(s + idx) == 'f')
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
