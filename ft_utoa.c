/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:25:45 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 09:54:42 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_dig(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static unsigned long	power(unsigned int base, int exp)
{
	unsigned long	result;

	result = 1;
	while (exp-- > 0)
		result *= base;
	return (result);
}

int	put_uint(unsigned int n)
{
	char	dig;
	int		len;
	int		r_len;

	len = count_dig(n);
	r_len = len;
	while (len >= 1)
	{
		dig = '0' + n / power(10, len-- - 1) % 10;
		ft_putchar_fd(dig, 1);
	}
	return (r_len);
}
