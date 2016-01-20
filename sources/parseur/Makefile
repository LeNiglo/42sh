##
## Makefile for projet in /home/andres_k//0file/file
## 
## Made by kevin andres
## Login   <andres_k@epitech.net>
## 
## Started on  Tue Feb 19 18:25:59 2013 kevin andres
## Last update Wed Apr 17 20:27:48 2013 kevin andres
##

SRC	=	main.c \
		my_classparam.c \
		my_str_to_wordtab.c \
		ad_elem_list.c \
		return_list.c \
		my_str.c \
		count_delim.c \
		help_parseur1.c \
		help_parseur2.c \
		remp_struct.c \
		exit_func.c \
		free_all.c \
		useless.c


OBJ	= $(SRC:.c=.o)

NAME	= parseur

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re: fclean all