/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:02:32 by klafi             #+#    #+#             */
/*   Updated: 2026/01/27 20:18:11 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b, t_counter *c)
{
	free_stack(a);
	free_stack(b);
	free(c);
}

void	adaptive(t_stack *a, t_stack *b, t_counter *c, double disorder_metric)
{
	if (disorder_metric < 0.2)
		selection_sort(a, b, c);
	else if (disorder_metric >= 0.2 && disorder_metric < 0.5)
		chunk_sort(a, b, c);
	else if (disorder_metric >= 0.5)
		radix(a, b, c);
}

int	root(t_stack *a, char *algo, int bench_mode)
{
	double		disorder_metric;
	t_stack		*b;
	t_counter	*c;

	b = init_stack();
	c = init_counter();
	disorder_metric = compute_disorder(a->size, a->top);
	if (!b || !c || disorder_metric == -1)
		return (write(2, "Error\n", 6), free_all(a, b, c), 1);
	if (algo && str_cmp(algo, "--simple"))
		selection_sort(a, b, c);
	else if (algo && str_cmp(algo, "--medium"))
		chunk_sort(a, b, c);
	else if (algo && str_cmp(algo, "--complex"))
		radix(a, b, c);
	else if ((algo && str_cmp(algo, "--adaptive")) || bench_mode)
		adaptive(a, b, c, disorder_metric);
	else if (!algo)
		adaptive(a, b, c, disorder_metric);
	if (bench_mode)
		bench(disorder_metric, algo, c);
	return (free_all(a, b, c), 0);
}
