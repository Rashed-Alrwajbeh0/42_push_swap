/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:33:20 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 13:37:56 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	string_to_int(char *str, int start, int end)
{
	long	ans;
	int		i;

	ans = 0;
	if (str[start] == '-')
	{
		start++;
		i = -1;
	}
	else
		i = 1;
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
	while (str[++i])
	{
		if (str[i] == 32 || str[i] == 9)
		{
			if (str[i + 1] == '\0')
				return (ans[++k] = '\0', ans);
			if (str[i + 1] != 32 && str[i + 1] != 9)
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
	int		i;
	int		start;
	char	*str;

	i = -1;
	start = 0;
	str = remove_spaces(s);
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == 9)
		{
			if (!help_with_checker(str, start, i, MyStack))
				return (0);
			start = i + 1;
		}
	}
	if (start != i)
		if (!help_with_checker(str, start, i, MyStack))
			return (0);
	return (free(str), 1);
}

float	compute_disorder(int size, t_node *tail, int total_pairs)
{
	int		mistakes;
	int		counter;
	int		i;
	t_node	*temp;

	mistakes = 0;
	counter = 0;
	while (counter < size)
	{
		i = ++counter;
		temp = tail->above;
		while (i++ < size)
		{
			total_pairs++;
			if (tail->content > temp->content)
				mistakes++;
			temp = temp->above;
		}
		tail = tail->above;
	}
	if (!total_pairs)
		return (2);
	return (mistakes / (double)total_pairs);
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		i;
	double		disorder_mitrec;
	int		bench_mode;
	char	*algo;
	t_stack	*a;
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
	free(c);
*/
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
	while (i < argc)
	{
		if (!checker(a, argv[i]))
			return (write(1, "Error\n", 6), 0);
		i++;
	}
	i = 0;
	disorder_mitrec = compute_disorder(a->size, a->bottom, 0);
	printf("disorder : %f.\n", disorder_mitrec);
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
