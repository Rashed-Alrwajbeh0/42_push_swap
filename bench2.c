/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:25:44 by klafi             #+#    #+#             */
/*   Updated: 2026/01/25 19:20:48 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_dig(int n)
{
	int	count;

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

void	write_strategy(char *algo, double disorder_metric)
{
	write(2, "[bench] strategy:  ", 18);
	if (!algo)
		algo = "--adaptive";
	if (str_cmp(algo, "--simple"))
		write(2, "Simple / O(n^2)", 15);
	else if (str_cmp(algo, "--medium"))
		write(2, "Medium / O(n*sqrt(n))", 21);
	else if (str_cmp(algo, "--complex"))
		write(2, "Complex / O(nlog n)", 19);
	else if (str_cmp(algo, "--adaptive"))
	{
		write(2, "Adaptive / ", 11);
		if (disorder_metric < 0.2)
			write(2, "O(n^2)", 6);
		else if (disorder_metric >= 0.2 && disorder_metric < 0.5)
			write(2, "O(n*sqrt(n))", 12);
		else if (disorder_metric >= 0.5)
			write(2, "O(n*log(n))", 11);
	}
	write(2, "\n", 1);
}

int	write_int(int n, int fd)
{
	char	dig;
	int		len;
	int		r_len;

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
