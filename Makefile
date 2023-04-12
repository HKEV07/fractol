# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 21:59:46 by ibenaait          #+#    #+#              #
#    Updated: 2023/03/06 15:45:32 by ibenaait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=CC
FLAGS= -Wall -Werror -Wextra
RM=rm -rf
NAME=fractol
BONUS=checker
FILES=	fractol ft_burn_ship ft_color ft_key_hook ft_mandelbrot \
		ft_mouse_hook ft_strcmp ft_julia ft_utlis_fun_fr

OBJ=$(FILES:=.o)

all: $(NAME)

%.o: %.c fractol.h
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ) fractol.h
	@$(CC)  $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all 