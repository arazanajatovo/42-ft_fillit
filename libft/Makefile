# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/08 20:18:35 by maxigarc     #+#   ##    ##    #+#        #
#    Updated: 2019/01/27 22:57:50 by maxigarc    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

OBJ += ./ft_atoi.o
OBJ += ./ft_bzero.o
OBJ += ./ft_isalnum.o
OBJ += ./ft_isalpha.o
OBJ += ./ft_isascii.o
OBJ += ./ft_isascii.o
OBJ += ./ft_isdigit.o
OBJ += ./ft_isprint.o
OBJ += ./ft_itoa.o
OBJ += ./ft_memalloc.o
OBJ += ./ft_memccpy.o
OBJ += ./ft_memchr.o
OBJ += ./ft_memcmp.o
OBJ += ./ft_memcpy.o
OBJ += ./ft_memdel.o
OBJ += ./ft_memmove.o
OBJ += ./ft_memrcpy.o
OBJ += ./ft_memset.o
OBJ += ./ft_putchar.o
OBJ += ./ft_putchar_fd.o
OBJ += ./ft_putendl.o
OBJ += ./ft_putendl_fd.o
OBJ += ./ft_putnbr.o
OBJ += ./ft_putnbr_fd.o
OBJ += ./ft_putstr.o
OBJ += ./ft_putstr_fd.o
OBJ += ./ft_strcat.o
OBJ += ./ft_strchr.o
OBJ += ./ft_strclr.o
OBJ += ./ft_strcmp.o
OBJ += ./ft_strcpy.o
OBJ += ./ft_strdel.o
OBJ += ./ft_strdup.o
OBJ += ./ft_strequ.o
OBJ += ./ft_striter.o
OBJ += ./ft_striteri.o
OBJ += ./ft_strjoin.o
OBJ += ./ft_strlcat.o
OBJ += ./ft_strlen.o
OBJ += ./ft_strmap.o
OBJ += ./ft_strmapi.o
OBJ += ./ft_strncat.o
OBJ += ./ft_strncmp.o
OBJ += ./ft_strncpy.o
OBJ += ./ft_strnequ.o
OBJ += ./ft_strnew.o
OBJ += ./ft_strnstr.o
OBJ += ./ft_strrchr.o
OBJ += ./ft_strsplit.o
OBJ += ./ft_strstr.o
OBJ += ./ft_strsub.o
OBJ += ./ft_strtrim.o
OBJ += ./ft_tolower.o
OBJ += ./ft_toupper.o
OBJ += ./ft_lstnew.o
OBJ += ./ft_lstdelone.o
OBJ += ./ft_lstdel.o
OBJ += ./ft_lstadd.o
OBJ += ./ft_lstiter.o
OBJ += ./ft_lstmap.o
OBJ += ./ft_sqrt.o
OBJ += ./ft_power.o
OBJ += ./ft_lstaddback.o
OBJ += ./ft_lstsplit.o
OBJ += ./ft_lstfold.o

HDR += ./includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
%.o: ./srcs/%.c
	gcc $(FLAGS) -I $(HDR) -c $^ -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
