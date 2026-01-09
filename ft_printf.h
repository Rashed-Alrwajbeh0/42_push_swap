/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:29:16 by klafi             #+#    #+#             */
/*   Updated: 2025/12/27 13:48:35 by klafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		dig_num_hex(unsigned long dec);

int		put_hex(unsigned long dec);

int		put_hex_cap(unsigned long dec);

int		han_c(va_list list);

int		han_s(va_list list);

int		han_p(va_list list);

int		han_di(va_list list);

int		han_u(va_list list);

int		han_x(va_list list);

int		han_xcap(va_list list);

int		han_mod(void);

int		ft_printf(const char *s, ...);

int		put_uint(unsigned int n);

int		put_int(int n);

int		ft_strlen(const char *s);

void	ft_putstr_fd(char *s, int fd);

void	ft_putchar_fd(char c, int fd);

#endif
