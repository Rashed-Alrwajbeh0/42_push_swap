#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b, t_counter *c)
{
	free_stack(a);
	free_stack(b);
	free(c);
}

int	root(t_stack *a, char *algo, int bench_mode)
{
	double		disorder_metric;
	t_stack		*b;
	t_counter	*c;

	b = init_stack();
	c = init_counter();
	if (!b || !c)
		return (ft_printf("Error\n"), free_all(a, b, c), 1);
	disorder_metric = compute_disorder(a->size, a->top);
	if (disorder_metric == -1)
		return (ft_printf("Error\n"), free_all(a, b, c), 1);
	if (bench_mode)
		return (ft_printf("Unfinished"), free_all(a, b, c), 1);
	if (algo && str_cmp(algo, "--simple"))
		selection_sort(a, b, c);
	else if (algo && str_cmp(algo, "--complex"))
		return (ft_printf("Unfinished"), free_all(a, b, c), 1);
	else if (algo && str_cmp(algo, "--medium"))
		return (ft_printf("Unfinished"), free_all(a, b, c), 1);
	else
		return (ft_printf("Unfinished"), free_all(a, b, c), 1);
	ft_printf("Disorder Metric : %f\n", disorder_metric);
	visualize(a);
	return (free_all(a, b, c), 0);
}
