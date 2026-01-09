/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:33:20 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/09 21:23:29 by ralrawaj         ###   ########.fr       */
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

	ans = malloc(len(str) + 1);
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

float	compute_disorder(t_node *tail, t_node *head)
{
	int		mistakes;
	float	total_pairs;
	t_node	*temp;

	mistakes = 0;
	total_pairs = 0;
	while (tail != head)
	{
		temp = tail->above;
		while (temp != head)
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
	return (mistakes / total_pairs);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		bench_mode;
	char	*algo;
	t_stack	*a;
	t_node	*tmp_print;

	bench_mode = 0;
	i = 1;
	if (stringcmp(argv[i], "--bench"))
	{
		bench_mode = 1;
		i = 2;
		printf("%d.\n", bench_mode);
	}
	algo = NULL;
	if (stringcmp(argv[i], "--simple") || stringcmp(argv[i], "--medium")
		|| stringcmp(argv[i], "--complex") || stringcmp(argv[i], "--adaptive"))
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
	tmp_print = a->top;
	while (tmp_print)
	{
		printf("d : %d.\n", tmp_print->content);
		tmp_print = tmp_print->below;
	}
	printf("s : %s.\n", algo);
	free_all(a);
	return (0);
}
