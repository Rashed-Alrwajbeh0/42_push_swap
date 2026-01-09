#include "push_swap.h"

int	add_to_stack(t_stack *s, int val)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->prev = *s;
	new_node->content = val;
	new_node->next = NULL;
	*s = new_node;
	return (1);
}

void	free_all(t_stack *MyStack)
{
	t_node	*current;
	t_node	*next_node;

	current = *MyStack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*MyStack = NULL;
}
