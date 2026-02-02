/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <klafi@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:50:45 by klafi             #+#    #+#             */
/*   Updated: 2026/02/02 14:21:11 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			dig_num_hex(unsigned long dec);
int			han_c(va_list list);
int			han_s(va_list list);
int			han_di(va_list list);
int			han_u(va_list list);
int			han_f(va_list list);
int			han_mod(void);
int			ft_printf(const char *s, ...);
int			put_uint(unsigned int n);
int			put_int(int n);
int			ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

#endif
