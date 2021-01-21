# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 10:51:13 by dohelee           #+#    #+#              #
#    Updated: 2021/01/20 12:25:54 by dohelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
SRCS = ft_printf.c ft_printf_c.c ft_printf_di.c ft_printf_p.c ft_printf_s.c ft_printf_uxX.c ft_printf_utils.c \
		ft_ltoa.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

LIBS_DIR = ./libft
LIBS = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(MAKE) all -C $(LIBS_DIR)
	cp $(LIBS_DIR)/$(LIBS) ./$(NAME)
	$(AR) $@ $^

# bonus : $(OBJS) $(OBJS_BONUS)
# 	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBS_DIR)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBS_DIR)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
