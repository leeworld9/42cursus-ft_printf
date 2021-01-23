# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 10:51:13 by dohelee           #+#    #+#              #
#    Updated: 2021/01/23 13:53:40 by dohelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
SRCS = ft_printf.c ft_printf_c.c ft_printf_di.c ft_printf_p.c ft_printf_s.c \
	ft_printf_ux.c ft_printf_common_utils.c ft_printf_di_utils.c ft_printf_tag_utils.c \
	ft_printf_exception.c ft_printf_s_utils.c ft_printf_ux_utils.c ft_printf_c_utils.c \
	ft_printf_p_utils.c
OBJS = $(SRCS:.c=.o)

LIBS_DIR = ./libft
LIBS = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(MAKE) all -C $(LIBS_DIR)
	cp $(LIBS_DIR)/$(LIBS) ./$(NAME)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBS_DIR)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBS_DIR)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
