# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/10 13:31:26 by paure        #+#   ##    ##    #+#        #
#    Updated: 2019/11/20 12:05:49 by paure       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS = 	ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c \
		ft_strjoin.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
		ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
		ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
		ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c \
		ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c \
		ft_countwords.c ft_countletters.c ft_cmpchar.c ft_strmapi.c \
		ft_itoa_base.c ft_lltoa_base.c ft_realloc.c ft_reverse_char.c \
		ft_strncat.c ft_utoa.c ft_istrchr.c ft_lltoa.c ft_stoa.c \
		ft_ustoa_base.c ft_ulltoa.c ft_ustoa.c

OBJS    = ${SRCS:.c=.o}

NAME    = libft.a

CC      = gcc

HD      = libft.h

MK		= Makefile

CFLAGS  = -Wall -Wextra -Werror -c

RM      = rm -f

BNS		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS2	= ${BNS:.c=.o}

$(NAME):    ${OBJS} ${HD} ${MK}
			ar rc ${NAME} ${OBJS}

bonus:		${OBJS2} ${OBJS} ${HD} ${MK}
			ar rc ${NAME} ${OBJS2} ${OBJS}

all:        ${NAME}

clean:
	            ${RM} ${OBJS} ${OBJS2}

fclean:		clean
	            ${RM} ${NAME} bonus

re:         fclean all

.PHONY:     all clean fclean re
