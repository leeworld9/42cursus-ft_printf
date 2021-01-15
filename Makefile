# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 10:51:13 by dohelee           #+#    #+#              #
#    Updated: 2021/01/15 08:12:57 by dohelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

LIBS_DIR = ./libft
LIBS = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	cp $(LIBS_DIR)/$(LIBS) ./$(NAME)
	$(AR) $@ $^

# bonus : $(OBJS) $(OBJS_BONUS)
# 	$(AR) $(NAME) $^

all: ft $(NAME)

ft:
	$(MAKE) all -C $(LIBS_DIR)

clean:
	$(MAKE) clean -C $(LIBS_DIR)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBS_DIR)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re ft
