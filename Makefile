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
VISUAL = visual
SRC  = src/main.c src/map.c src/algorithm.c src/dist.c
V_SRC = vsl/main.c vsl/additional.c vsl/draw.c
OBJ = $(SRC:.c=.o)
V_OBJ = $(V_SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
SEGF = -g -fsanitize=address 
GRAPH = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(VISUAL)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME) -I libft/libftsrc -I libft
	@echo "\033[32m\033[36mFiller \033[32mdone\033[0m"
	
$(VISUAL): $(V_OBJ)
	@make -C ./libft
	gcc $(FLAGS) $(GRAPH) $(SEGF) $(V_OBJ) -L libft/ -lft -o $(VISUAL)
	@echo "\033[32m\033[36mVisualization \033[32mdone\033[0m"

%.o: %.c includes/filler.h includes/visual.h
	gcc -c $< -o $@ $(FLAGS) -I includes/

clean:
	@rm -f $(OBJ) $(V_OBJ)

fclean: clean
	@rm -f $(NAME) $(VISUAL) 

re: fclean all