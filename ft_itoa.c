/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:21:12 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 09:53:19 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_dig(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		count = 1;
		n *= -1;
	}
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

int	put_int(int n)
{
	char	dig;
	int		len;
	int		r_len;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (ft_strlen("-2147483648"));
	}
	len = count_dig(n);
	r_len = len;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len--;
	}
	while (len >= 1)
	{
		dig = '0' + n / power(10, len-- - 1) % 10;
		write(1, &dig, 1);
	}
	return (r_len);
}
