# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 08:37:13 by bguyot            #+#    #+#              #
#    Updated: 2021/12/02 16:34:50 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = ft_hexdump
FLAGS = -Wall -Wextra -Werror
LIB   = -L. -lft
SRCS  = ft_hexdump.c poubelle.c
OBJS  = ft_hexdump.o poubelle.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
