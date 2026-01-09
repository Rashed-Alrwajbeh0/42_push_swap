/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:43:57 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 15:19:53 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

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

int			dig_num_hex(unsigned long dec);
int			put_hex(unsigned long dec);
int			put_hex_cap(unsigned long dec);
int			han_c(va_list list);
int			han_s(va_list list);
int			han_p(va_list list);
int			han_di(va_list list);
int			han_u(va_list list);
int			han_x(va_list list);
int			han_xcap(va_list list);
int			han_mod(void);
int			ft_printf(const char *s, ...);
int			put_uint(unsigned int n);
int			put_int(int n);
int			ft_strlen(const char *s);
int			add_to_stack(t_stack *s, int val);
int			checker(t_stack *MyStack, char *s);
int			stringcmp(char *str1, char *str2);
int			help_with_string_to_int(char *str, int start, int end);
int			help_with_checker(char *str, int start, int end, t_stack *MyStack);
int			is_duplicate(t_node *top, int val);
long		string_to_int(char *str, int start, int end);
long		len(char *str);
float		compute_disorder(t_node *tail, t_node *head);
char		*remove_spaces(char *str);
void		free_all(t_stack *MyStack);
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
void		visualize(t_stack *stack);
void		push(t_stack *stack, int elem);
void		rrr(t_stack *stack_a, t_stack *stack_b, t_counter *c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
t_stack		*init_stack(void);
t_node		*pop(t_stack *stack);
t_counter	*init_counter(void);
#endif
