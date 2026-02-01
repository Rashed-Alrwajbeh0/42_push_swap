/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:04:08 by klafi             #+#    #+#             */
/*   Updated: 2026/01/25 19:26:08 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_disorder(double disorder_metric)
{
	double	num;
	int		int_num;

	write(2, "[bench] disorder:  ", 18);
	disorder_metric *= 100;
	num = disorder_metric;
	write_int(num / 1, 2);
	num *= 10.0;
	int_num = (int)num;
	int_num %= 10;
	write(2, ".", 1);
	write_int(int_num, 2);
	num *= 10.0;
	int_num = (int)num;
	int_num %= 10;
	write_int(int_num, 2);
	write(2, "%", 1);
	write(2, "\n", 1);
}

void	write_total_ops(t_counter *c)
{
	int	total_ops;

	write(2, "[bench] total_ops:  ", 19);
	total_ops = c->sa + c->sb + c->ss + c->pa + c->pb + c->ra + c->rb + c->rr
		+ c->rra + c->rrb + c->rrr;
	write_int(total_ops, 2);
	write(2, "\n", 1);
}

void	write_ops1(t_counter *c)
{
	write(2, "[bench] ", 8);
	write(2, "sa:  ", 5);
	write_int(c->sa, 2);
	write(2, "  sb:  ", 7);
	write_int(c->sb, 2);
	write(2, "  ss: ", 7);
	write_int(c->ss, 2);
	write(2, "  pa: ", 7);
	write_int(c->pa, 2);
	write(2, "  pb: ", 7);
	write_int(c->pb, 2);
	write(2, "\n", 1);
}

void	write_ops2(t_counter *c)
{
	write(2, "[bench] ", 8);
	write(2, "ra:  ", 5);
	write_int(c->ra, 2);
	write(2, "  rb:  ", 7);
	write_int(c->rb, 2);
	write(2, "  rr: ", 7);
	write_int(c->rr, 2);
	write(2, "  rra: ", 8);
	write_int(c->rra, 2);
	write(2, "  rrb: ", 8);
	write_int(c->rrb, 2);
	write(2, "  rrr: ", 8);
	write_int(c->rrr, 2);
	write(2, "\n", 1);
}

void	bench(double disorder_metric, char *algo, t_counter *c)
{
	write_disorder(disorder_metric);
	write_strategy(algo, disorder_metric);
	write_total_ops(c);
	write_ops1(c);
	write_ops2(c);
}
