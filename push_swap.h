/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:43:57 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/10 13:36:31 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf.h"
# include "stack.h"

int			add_to_stack(t_stack *s, int val);
int			checker(t_stack *MyStack, char *s);
int			str_cmp(char *str1, char *str2);
int			help_with_string_to_int(char *str, int start, int end);
int			help_with_checker(char *str, int start, int end, t_stack *MyStack);
int			is_duplicate(int size, t_node *top, int val);
long		string_to_int(char *str, int start, int end);
long		len(char *str);
float		compute_disorder(int size, t_node *tail, int total_pairs);
char		*remove_spaces(char *str);

#endif
