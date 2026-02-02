/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:02:32 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 14:05:43 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b, t_counter *c)
{
	free_stack(a);
	free_stack(b);
	free(c);
}

int	adaptive(t_stack *a, t_stack *b, t_counter *c, double disorder_metric)
{
	int	success;

	success = 1;
	if (disorder_metric < 0.2)
		selection_sort(a, b, c);
	else if (disorder_metric >= 0.2 && disorder_metric < 0.5)
		success = chunk_sort(a, b, c);
	else if (disorder_metric >= 0.5)
		success = radix(a, b, c);
	return (success);
}

int	root(t_stack *a, char *algo, int bench_mode)
{
	double		disorder_metric;
	t_stack		*b;
	t_counter	*c;
	int			success;

	success = 1;
	b = init_stack();
	c = init_counter();
	disorder_metric = compute_disorder(a->size, a->top);
	if (!b || !c || disorder_metric == -1)
		return (write(2, "Error\n", 6), free_all(a, b, c), 1);
	if (algo && str_cmp(algo, "--simple"))
		selection_sort(a, b, c);
	else if (algo && str_cmp(algo, "--medium"))
		success = chunk_sort(a, b, c);
	else if (algo && str_cmp(algo, "--complex"))
		success = radix(a, b, c);
	else if ((algo && str_cmp(algo, "--adaptive")) || bench_mode)
		success = adaptive(a, b, c, disorder_metric);
	else if (!algo)
		success = adaptive(a, b, c, disorder_metric);
	if (bench_mode)
		bench(disorder_metric, algo, c);
	return (free_all(a, b, c), success);
}
