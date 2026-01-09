#include "push_swap.h"

long	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	stringcmp(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = -1;
	while (str1[++i])
		if (str1[i] != str2[i])
			return (0);
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

int	is_duplicate(t_stack MyStack, int val)
{
	while (MyStack)
	{
		if (val == MyStack->content)
			return (1);
		MyStack = MyStack->next;
	}
	return (0);
}

int	help_with_string_to_int(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] > '9' || str[start] < '0')
			return (0);
		start++;
	}
	return (1);
}

int	help_with_checker(char *str, int start, int end, t_stack *MyStack)
{
	long	temp;

	temp = string_to_int(str, start, end);
	if (temp == 2147483648 || is_duplicate(*MyStack, temp))
		return (free_all(MyStack), free(str), 0);
	else
		add_to_stack(MyStack, temp);
	return (1);
}
