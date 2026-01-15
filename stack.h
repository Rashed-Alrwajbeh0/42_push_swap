/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:43:18 by klafi             #+#    #+#             */
/*   Updated: 2026/01/10 13:36:56 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct node
{
	struct node	*above;
	struct node	*below;
	int			content;
	char		*number_in_binary;
}	t_node;

typedef struct list
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct operations
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

void		push(t_stack *stack, int elem);
t_node		*pop(t_stack *stack);
t_stack		*init_stack(void);
t_counter	*init_counter(void);
void		visualize(t_stack *stack);
void		free_stack(t_stack *stack);

void		sa(t_stack *stack_a, t_counter *c);
void		sb(t_stack *stack_b, t_counter *c);
void		ss(t_stack *stack_a, t_stack *stack_b, t_counter *c);
void		pa(t_stack *stack_a, t_stack *stack_b, t_counter *c);
void		pb(t_stack *stack_a, t_stack *stack_b, t_counter *c);
void		ra(t_stack *stack_a, t_counter *c);
void		rb(t_stack *stack_b, t_counter *c);
void		rr(t_stack *stack_a, t_stack *stack_b, t_counter *c);
void		rra(t_stack *stack_a, t_counter *c);
void		rrb(t_stack *stack_b, t_counter *c);
void		rrr(t_stack *stack_a, t_stack *stack_b, t_counter *c);

#endif
