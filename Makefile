# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klafi <kanan.lafi@learner.42.tech>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 14:24:57 by klafi             #+#    #+#              #
#    Updated: 2026/01/09 19:15:59 by klafi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRCS = ft_printf.c ft_utoa.c han1.c han2.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c
OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
$(wildcard %.o) : $(wildcard %.c)
	cc $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
