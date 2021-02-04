# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/16 12:26:52 by arazanaj     #+#   ##    ##    #+#        #
#    Updated: 2019/03/29 10:47:28 by maxigarc    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

OBJ += ./srcs/main.o
OBJ += ./srcs/list.o
OBJ += ./srcs/map.o
OBJ += ./srcs/check.o
OBJ += ./srcs/solver.o

LIBFT = ./libft/libft.a

HDR += ./includes/ft_fillit.h

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HDR) -c $^ -o $@

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
