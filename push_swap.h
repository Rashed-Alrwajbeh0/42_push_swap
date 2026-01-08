#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct node
{
	int	content;
	struct node *next;
} node;

typedef node *stack;

int		add_to_stack(stack *s, int val);
int		checker(stack *MyStack, char **algo, char *s);
int		is_duplicate(stack MYstack, int val);
long	string_to_int(char *str, int start, int end);
long	len(char *str);
char	*help_with_checker2(int start, int end, char *str, stack *MyStack);
char	*remove_spaces(char *str);
char	*help_with_checker(int start, int end, char *s, stack *MyStack);
char	*to_lower(int start, int end, char *str);
void	FreeAll(stack *MyStack);
void    help_with_to_lower(int *num, int *algo, char *str, int end);
#endif
