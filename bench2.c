/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:25:44 by klafi             #+#    #+#             */
/*   Updated: 2026/01/15 11:34:33 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int write_int(int n, int fd)
{
    char    dig;
    int     len;
    int     r_len;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (ft_strlen("-2147483648"));
	}
	len = count_dig(n);
	r_len = len;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	len--;
	}
	while (len >= 1)
	{
		dig = '0' + n / power(10, len-- - 1) % 10;
		write(fd, &dig, 1);
	}
	return (r_len);
}
