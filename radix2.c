#include "push_swap.h"

char	help_radix2(int idx, int j, t_node *head)
{
	t_node	*temp;

	temp = head;
	while (j)
	{
		temp = temp->below;
		j--;
	}
	return (temp->bin[idx]);
}
