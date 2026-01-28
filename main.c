/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:33:20 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/27 19:37:14 by klafi            ###   ########.fr       */
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
	if (!is_int(str, start, end))
		return (2147483648);
	while (start < end)
	{
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

double	compute_disorder(int size, t_node *top)
{
	int		mistakes;
	int		i;
	int		total_pairs;
	t_node	*temp;

	if (size == 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	while (size > 0)
	{
		i = --size;
		temp = top->below;
		while (i-- > 0)
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
	int		bench_mode;
	char	*algo;
	t_stack	*a;

	if (argc == 1)
		return (0);
	bench_mode = 0;
	i = 1;
	if (str_cmp(argv[i], "--bench"))
		bench_mode = i++;
	algo = NULL;
	if (str_cmp(argv[i], "--simple") || str_cmp(argv[i], "--medium")
		|| str_cmp(argv[i], "--complex") || str_cmp(argv[i], "--adaptive"))
		algo = argv[i++];
	a = init_stack();
	if (!a)
		return (write(2, "Error\n", 6), 1);
	while (argc-- > i)
		if (!checker(a, argv[argc]))
			return (write(2, "Error\n", 6), 1);
	return (root(a, algo, bench_mode));
}
