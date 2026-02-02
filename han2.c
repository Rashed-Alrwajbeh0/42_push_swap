/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:11:11 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 14:12:48 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	han_mod(void)
{
	write(1, "%", 1);
	return (1);
}

int	han_f(va_list list)
{
	double	num;
	int		int_num;
	int		len;

	num = va_arg(list, double);
	len = put_int(num / 1);
	num *= 100.0;
	int_num = (int)num;
	int_num %= 100;
	len += write(1, ".", 1);
	len += put_int(int_num);
	return (len);
}
