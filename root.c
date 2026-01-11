#include "push_swap.h"

void	root(t_stack *a, char *algo, int bench_mode)
{
	double		disorder_mitrec;
	t_stack		*b;
	t_counter	*c;

	b = init_stack();
	c = init_counter();
	if (!b || !c)
	{
		free_stack(a);
		free(c);
		ft_printf("Error\n");
		return ;
	}
	disorder_mitrec = compute_disorder(a->size, a->top);
	if (disorder_mitrec == -1)
	{
		free_stack(a);
		free(b);
		free(c);
		return ;
	}
	if (bench_mode)
	{
		free_stack(a);
		free(b);
		free(c);
		ft_printf("Not completed :( \n");
		return ;
	}
	if (algo && str_cmp(algo, "--simple"))
		selection_sort(a, b, c);
	else if (algo && str_cmp(algo, "--complex"))
	{
		free_stack(a);
		free(b);
		free(c);
		ft_printf("Not completed :( \n");
		return ;
	}
	else if (algo && str_cmp(algo, "--medium"))
	{
		free_stack(a);
		free(b);
		free(c);
		ft_printf("Not completed :( \n");
	}
	else
	{
		free_stack(a);
		free(b);
		free(c);
		ft_printf("Not completed :( \n");
		return ;
	}
	ft_printf("Disorder Mitrec : %f\n", disorder_mitrec);
	visualize(a);
	free_stack(a);
	free(b);
	free(c);
}
