# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/12 14:53:18 by yait-bam          #+#    #+#              #
#    Updated: 2019/02/03 13:48:27 by yait-bam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror
ATTACH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft

SRC = main.c check_args.c parse_args.c event_key.c \
	  map_proj.c  proj.c draw_line.c read_args.c  

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH)

run42:
	./fdf tests/42.fdf

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
