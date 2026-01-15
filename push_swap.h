/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:43:57 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/11 11:43:14 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf.h"
# include "stack.h"

int			add_to_stack(t_stack *s, int val);
int			checker(t_stack *MyStack, char *s);
int			str_cmp(char *str1, char *str2);
int			is_int(char *str, int start, int end);
int			help_with_checker(char *str, int start, int end, t_stack *MyStack);
int			is_duplicate(int size, t_node *top, int val);
int			min_up(t_stack *stack, int *val, int chunck_size);
int			min_down(t_stack *stack, int *val, int chunck_size);
int			chunck_sort(t_stack *a, t_stack *b, t_counter *c, int chunck_size);
int			*indexing(t_stack *mystack);
int			radix(t_stack *a, t_stack *b, t_counter *c);
int			convert_stack_to_binary(t_stack *mystack);
int			max(int num);
long		string_to_int(char *str, int start, int end);
long		len(char *str);
double		compute_disorder(int size, t_node *tail);
char		*remove_spaces(char *str);
char		*convert_to_binary(int num, int idx);
void		selection_sort(t_stack *a, t_stack *b, t_counter *c);
void		return_stack(t_stack *mystack, int *sorted_nums);
void		switch_stack_content(t_stack *mystack, int *sorted_arr);
void		selection(t_stack *a, t_stack *b, t_counter *c);
void		sort_array(int *arr, int size);
void		chunck_helper(int num1, int num2, t_stack *a, t_counter *c);
void		selection_three(t_stack *a, t_counter *c);
void		help_radix(t_stack *a, t_stack *b, t_counter *c, int idx);
int			root(t_stack *a, char *algo, int bench_mode);
int			check_order(t_node *top, int size);
#endif
