/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:24:48 by klafi             #+#    #+#             */
/*   Updated: 2026/01/09 20:17:23 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>

typedef struct node
{
    struct node	*above;
    struct node	*below;
    int			content;
}	t_node;

typedef struct list
{
	t_node	*top;
	t_node	*bottom;
	int     size;
}   t_stack;

typedef stuct 
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counter;

#endif
