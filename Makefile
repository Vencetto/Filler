# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 18:34:19 by vzomber           #+#    #+#              #
#    Updated: 2018/03/08 18:34:20 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vzomber.filler
SRC  = src/main.c src/map.c src/algorithm.c src/dist.c src/additional.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
SEGF = -g -fsanitize=address 
all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
	@echo "\033[32mmake for \033[36mFillit \033[32mdone\033[0m"
	
%.o: %.c include/filler.h
	gcc -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all