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
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = push_swap.h
NAME = push_swap
PRINTF = printf.a
SRCS1 = ft_printf.c \
       ft_utoa.c \
       han1.c \
       han2.c \
       ft_itoa.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_strlen.c

SRCS2 = helper_functions_for_main.c \
       push.c \
       reverse_rotate.c \
       stack.c \
       main.c \
       rotate.c \
       stack_functions.c \
       swap.c \

OBJS1 := $(SRCS1:.c=.o)
OBJS2 := $(SRCS2:.c=.o)

all : $(PRINTF) $(NAME)

$(NAME): $(OBJS2) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS2) $(PRINTF) -o $(NAME)
$(PRINTF) : $(OBJS1)
	ar rcs $(PRINTF) $(OBJS1)
%.o :%.c $(HEADERS)
	cc $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJS1) $(OBJS2)
fclean : clean
	rm -f $(NAME) $(PRINTF)
re : fclean all
