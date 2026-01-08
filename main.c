#include "push_swap.h"

void	help_with_to_lower(int *num, int *algo, char *str, int end)
{
	int	i;

	i = -1;
	while (++i < end)
	{
		if (str[i] >= '0' && str[i] <= '9')
			*num = 1;
		else
			*algo = 1;
	}
}

char	*to_lower(int start, int end, char *str)
{
	int		num;
	int		algo;
	int		ans_index;
	char	*ans;

	ans_index = -1;
	num = 0;
	algo = 0;
	if (str == NULL)
		return (NULL);
	ans = malloc(end - start + 1);
	if (!ans)
		return (NULL);
	if (str[start] == '-')
		help_with_to_lower(&num, &algo, str + start + 1, end - start - 1);
	else
		help_with_to_lower(&num, &algo, str + start, end - start);
	if (num && algo)
		return (free(ans), NULL);
	else if (num)
		return (free(ans), ans = malloc(2), ans[0] = '1', ans[1] = '\0', ans);
	while (++start - 1 < end)
		if (str[start - 1] >= 'A' && str[start - 1] <= 'Z')
			ans[++ans_index] = str[start - 1] + 32;
		else
			ans[++ans_index] = str[start - 1];
	ans[++ans_index] = '\0';
	return (ans);
}

long	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	string_to_int(char *str, int start, int end)
{
	long	ans;
	int	i;

	ans = 0;
	if (str[start] == '-')
	{
		start++;
		i = -1;
	}
	else
		i = 1;
	while(start < end)
	{
		if (str[start] == '.')
			return (0);
		ans *= 10;
		ans += str[start] - '0';
		start++;
	}
	if (ans < -2147483648 || ans > 2147483647)
		return (0);
	return (i * ans);
}

int	stringcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	int	i;

	i = -1;
	while (str1[++i])
		if (str1[i] != str2[i])
			return (0);
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

char	*help_with_checker(int start, int end, char *s, stack *MyStack)
{
	char	*temp;
	long	num;

	temp = to_lower(start, end , s);
	if (temp == NULL)
		return (NULL);
	else if (temp[0] == '1')
	{
		num = string_to_int(s, start, end);
		free(temp);
		if (!num)
			return (NULL);
		if (is_duplicate(*MyStack, num))
			return (NULL);
		add_to_stack(MyStack, num);
		return ("1\0");
	}
	else if (stringcmp(temp, "--simple"))
		return (temp);
	else if (stringcmp(temp, "--medium"))
		return (temp);
	else if (stringcmp(temp, "--complex"))
		return (temp);
	else if (stringcmp(temp, "--adaptive"))
		return (temp);
	else
		return (NULL);
}

char	*help_with_checker2(int start, int end, char *str, stack *MyStack)
{
	char	*temp;

	temp = help_with_checker(start, end, str, MyStack);
	if (!temp)
		return (free(temp), FreeAll(MyStack), NULL);
	return (temp);
}

int	is_duplicate(stack MyStack, int val)
{

	while (MyStack)
	{
		if (val == MyStack->content)
			return (1);
		MyStack = MyStack->next;
	}
	return (0);
}

char	*remove_spaces(char *str)
{
	char	*ans;
	int	i;
	int	k;

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

int	checker(stack *MyStack, char **algo, char *s)
{
	int		i;
	int		start;
	char	*str;
	char	*temp;

	i = -1;
	start = 0;
	str = remove_spaces(s);
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == 9)
		{
			if (i - start == 1 && str[start] == '0')
			{
				if (is_duplicate(*MyStack, 0))
					return (FreeAll(MyStack), 0);
				add_to_stack(MyStack, 0);
			}
			else if (i - start == 1 && str[start] == '1')
			{
				if (is_duplicate(*MyStack, 1))
					return (FreeAll(MyStack), 0);
				add_to_stack(MyStack, 1);
			}
			else
			{
				temp = help_with_checker(start, i, str, MyStack);
				if (temp == NULL)
					return (FreeAll(MyStack), free(str), 0);
				else if (!stringcmp(temp, "1"))
				{
					if (!*algo)
						*algo = temp;
					else
						return (free(*algo), free(str), FreeAll(MyStack), 0);
				}
			}
			start = i + 1;
		}
	}
	if (i - start == 1 && str[start] == '0')
	{
		if (is_duplicate(*MyStack, 0))
			return (free(str), FreeAll(MyStack), 0);
		add_to_stack(MyStack, 0);
	}
	else
	{
		temp = help_with_checker(start, i, str, MyStack);
		if (!temp)
			return (free(str), FreeAll(MyStack), 0);
		if (start == 0 && !stringcmp(temp, "1") && !*algo)
			return (*algo = temp, free(str), 1);
		else if (start == 0 && !stringcmp(temp, "1") && algo)
			return (free(str), FreeAll(MyStack), 0);
	}
	free(str);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*algo;
	stack	a;
	node	*tmp_print;

	i = 1;
	algo = NULL;
	a = NULL;
	while (i < argc)
	{
		if (!checker(&a, &algo, argv[i]))
		{
			write(1, "Error\n", 6);
			FreeAll(&a); 
			free(algo);
			return (0);
		}
		i++;
	}
	tmp_print = a;
	while (tmp_print)
	{
		printf("d : %d.\n", tmp_print->content);
		tmp_print = tmp_print->next;
	}
	printf("s : %s.\n", algo);

	FreeAll(&a);
	free(algo);
	return (0);
}
