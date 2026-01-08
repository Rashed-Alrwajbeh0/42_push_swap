# include "push_swap.h"

int	add_to_stack(stack *s, int val)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return (0);
	new_node->content = val;
	new_node->next = *s;
	*s = new_node;
	return (1);
}

void	FreeAll(stack *MyStack)
{
    node	*current;
    node	*next_node;

    current = *MyStack;
    while (current)
    {
	    next_node = current->next;
	free(current);
	current = next_node;
    }
    *MyStack = NULL;
}
