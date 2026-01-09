#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef t_node	*t_stack;

int			add_to_stack(t_stack *s, int val);
int			checker(t_stack *MyStack, char *s);
int			stringcmp(char *str1, char *str2);
int			help_with_string_to_int(char *str, int start, int end);
int			help_with_checker(char *str, int start, int end, t_stack *MyStack);
int			is_duplicate(t_stack MYstack, int val);
long		string_to_int(char *str, int start, int end);
long		len(char *str);
float		compute_disorder(t_node *tail, t_node *head);
char		*remove_spaces(char *str);
void		free_all(t_stack *MyStack);
#endif
