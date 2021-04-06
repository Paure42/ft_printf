# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/12 19:11:21 by paure        #+#   ##    ##    #+#        #
#    Updated: 2019/11/20 12:06:06 by paure       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

SOURCES = ft_printf.c \
		  ft_printf_padding.c \
		  ft_printf_read.c \
		  ft_printf_convert.c \
		  ft_printf_convert2.c \
		  ft_printf_point.c \
		  ft_printf_zero.c \
		  ft_printf_rules.c \
		  ft_printf_convert_bonus.c \
		  ft_printf_padding_bonus.c \
		  ft_printf_read_bonus.c \
		  ft_printf_convert_bonus2.c \

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = sources

HD = sources

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_S)/,$(SOURCES:.c=.o))

all: $(NAME)

bonus:	${NAME}

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_S)/%.o: $(DIR_S)/%.c
	$(CC) $(CFLAGS) -I $(HD) -o $@ -c $<

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

