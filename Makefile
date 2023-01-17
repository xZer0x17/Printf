# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alflores <alflores@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 23:29:53 by alflores          #+#    #+#              #
#    Updated: 2023/01/18 00:26:44 by alflores         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c tools.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra -I ../libft

all: $(NAME)

$(NAME): printf.h
	make -C ../libft
	cp ../libft/libft.h ./
	cp ../libft/libft.a ./$(NAME)
	make fclean -C ../libft
	gcc $(CFLAG) -c $(SRC)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) libft.h libft.a

re: fclean all

.PHONY: all clean fclean