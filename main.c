/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:33:20 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 19:19:55 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	string_to_int(char *str, int start, int end)
{
	long	ans;
	int		i;

	ans = 0;
	i = 1;
	if (str[start] == '-')
	{
		start++;
		i = -1;
	}
	else if (str[start] == '+')
		start++;
	if (!help_with_string_to_int(str, start, end))
		return (2147483648);
	while (start < end)
	{
		if (str[start] == '.')
			return (2147483648);
		ans *= 10;
		ans += str[start] - '0';
		start++;
	}
	if (ans * i < -2147483648 || ans * i > 2147483647)
		return (2147483648);
	return (i * ans);
}

char	*remove_spaces(char *str)
{
	char	*ans;
	int		i;
	int		k;

	ans = malloc(ft_strlen(str) + 1);
	if (!ans)
		return (NULL);
	i = -1;
	k = -1;
	while (*str == 32)
		str++;
	while (str[++i])
	{
		if (str[i] == 32)
		{
			if (str[i + 1] == '\0')
				return (ans[++k] = '\0', ans);
			if (str[i + 1] != 32)
				ans[++k] = str[i];
		}
		else
			ans[++k] = str[i];
	}
	ans[++k] = '\0';
	return (ans);
}

int	checker(t_stack *MyStack, char *s)
{
	int		start;
	int		end;
	char	*str;

	str = remove_spaces(s);
	if (!str)
		return (0);
	start = ft_strlen(str) - 1;
	end = start + 1;
	while (start >= 0)
	{
		if (str[start] == ' ')
		{
			if (!help_with_checker(str, start + 1, end, MyStack))
				return (0);
			end = start;
		}
		start--;
	}
	if (start != end)
		if (!help_with_checker(str, start + 1, end, MyStack))
			return (0);
	return (free(str), 1);
}

<<<<<<< HEAD
float	compute_disorder(int size, t_node *top, int total_pairs)
=======
double	compute_disorder(int size, t_node *tail, int total_pairs)
>>>>>>> 3fa04fc (added the selection sort)
{
	int		mistakes;
	int		i;
	t_node	*temp;

	mistakes = 0;
	while (size)
	{
		i = --size;
		temp = top->below;
		while (i--)
		{
			total_pairs++;
			if (top->content > temp->content)
				mistakes++;
			temp = temp->below;
		}
		top = top->below;
	}
	if (!total_pairs)
		return (-1);
	return (mistakes / (double)total_pairs);
}

int	main(int argc, char *argv[])
{
	int		i;
	double		disorder_metric;
	int		bench_mode;
	char	*algo;
	t_stack	*a;
	t_stack *b;
	t_node	*tmp_print;

/*
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();
	t_counter *c = init_counter();
	push(stack_a, 1);
	push(stack_a, 2);
	push(stack_a, 3);

	push(stack_b, 4);
	push(stack_b, 5);
	push(stack_b, 6);

	ft_printf("===============\nstack a : \n");
    visualize(stack_a);
	ft_printf("\nstack b : \n");
    visualize(stack_b);

	rra(stack_a, c);
	ft_printf("===============\nstack a : \n");
    visualize(stack_a);
	ft_printf("\nstack b : \n");
    visualize(stack_b);

	pa(stack_a, stack_b, c);
	ft_printf("===============\nstack a : \n");
    visualize(stack_a);
	ft_printf("\nstack b : \n");
    visualize(stack_b);

	rrb(stack_b, c);
	ft_printf("===============\nstack a : \n");
    visualize(stack_a);
	ft_printf("\nstack b : \n");
    visualize(stack_b);

	pa(stack_a, stack_b, c);
	ft_printf("===============\nstack a : \n");
    visualize(stack_a);
	ft_printf("\nstack b : \n");
    visualize(stack_b);

	rrr(stack_a, stack_b, c);
	ft_printf("===============\nstack a : \n");
    visualize(stack_a);
	ft_printf("\nstack b : \n");
    visualize(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(c);*/
	bench_mode = 0;
	i = 1;
	if (str_cmp(argv[i], "--bench"))
	{
		bench_mode = 1;
		i = 2;
		ft_printf("bench mode : %d.\n", bench_mode);
	}
	algo = NULL;
	if (str_cmp(argv[i], "--simple") || str_cmp(argv[i], "--medium")
		|| str_cmp(argv[i], "--complex") || str_cmp(argv[i], "--adaptive"))
	{
		algo = argv[i];
		i++;
	}
	a = init_stack();
	while (argc > i)
	{
		if (!checker(a, argv[argc - 1]))
			return (write(1, "Error\n", 6), 0);
		argc--;
	}
	i = 0;
	visualize(a);
	disorder_metric = compute_disorder(a->size, a->top, 0);
	ft_printf("disorder : %f.\n", disorder_metric);
	tmp_print = a->top;
	while (i < a->size)
	{
		ft_printf("d : %d.\n", tmp_print->content);
		tmp_print = tmp_print->below;
		i++;
	}
	ft_printf("s : %s.\n", algo);
	free_stack(a);
	return (0);
}
