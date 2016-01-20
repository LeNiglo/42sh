##
## Makefile for Minishell2 in /home/lefran_g//Projects/B2/Minishell2
##
## Made by guillaume lefrant
## Login   <lefran_g@epitech.net>
##
## Started on  Wed Feb  6 11:30:57 2013 guillaume lefrant
## Last update Wed May 22 15:12:04 2013 guillaume lefrant
##

NAME	=	mysh

CFLAGS	=	 -g -Wall -Wextra

SRCS	=	main.c \
		env_cd.c \
		get_next_line.c \
		modif_setenv.c \
		change_env.c \
		my_str_word.c \
	  	sources/prompt/prompt.c \
		sources/parseur/ad_elem_list.c \
		sources/parseur/count_delim.c \
		sources/parseur/exit_func.c \
		sources/parseur/free_all.c \
		sources/parseur/help_parseur1.c \
		sources/parseur/help_parseur2.c \
		sources/parseur/my_classparam.c \
	  	sources/parseur/my_str.c \
	  	sources/parseur/my_str2.c \
	  	sources/parseur/my_str_to_wordtab.c \
	  	sources/parseur/remp_struct.c \
	  	sources/parseur/return_list.c \
	  	sources/parseur/useless.c \
	  	sources/pipes/exe_all.c \
	  	sources/pipes/my_dup2.c \
	  	sources/pipes/my_execve.c \
	  	sources/pipes/my_fork.c \
	  	sources/pipes/my_pipe.c \
	  	sources/pipes/pipes.c \
	  	sources/pipes/red.c \
	  	sources/my_put_nbr.c \
	  	sources/my_putstr.c \
	  	sources/my_putchar.c \
	  	sources/my_strcat.c \
	  	sources/my_strcmp.c \
		sources/my_strncmp.c \

OBJS	= 	$(SRCS:.c=.o)

$(NAME):  $(OBJS)
	cc $(OBJS) $(CFLAGS) -o $(NAME)

all:  $(NAME)

clean:
	rm -f $(OBJS)

fclean:	 clean
	rm -f $(NAME)

re:	fclean all

love:
	@echo 'not war?'

itsafe:
	@makes
