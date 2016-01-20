/*
** shell.h for 42SH in /afs/epitech.net/users/epitech_2017/lefran_g/public/42SH
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Thu Apr  4 11:20:02 2013 guillaume lefrant
** Last update Wed May 22 15:17:01 2013 guillaume lefrant
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

# include "sources/parseur/parseur.h"
# include "sources/pipes/pipe.h"
# include "sources/pipes/red.h"

# define CHAR_READ	(42000)

typedef struct		s_shell
{
  char			**env;
  int			status;
}			t_shell;

int			my_strncmp(char *, char *, int);
int			my_strcmp(char *, char *);
char			*my_strcat(char *, char *);
void			aff_prompt(char *, char **);
void			my_putchar(char);
void			my_putstr(char *);
void			my_put2str(char **);
int			my_strlen(char *);

/*
** main.c
*/

char			*check_in_path(char **, char *);
int			check_builtins(char **cmd, t_shell *sh);
int			wait_instructions(t_param exe, char **envp);
t_shell			*ini_sh(char **envp);

/*
** modif_setenv.c
*/

char			**add_elem_envp(char **envp, char *new);

/*
** my_str_word.c
*/

char			**my_str_word(char *str, char delim, int start, int addmot);
char			*remp_str(char *str, char delim, int *pos, int addmot);
int			count_word_str(char *str, char delim);

/*
** env_cd.c
*/

int			do_setenv(char **foo, t_shell *sh);
int			do_unsetenv(char **foo, char **envp);
int			do_env(char **envp);
int			do_cd(char **foo, char **envp);
char			**help_do_cd(char **foo, char **envp);

/*
** change_env.c
*/

char			**change_env(char *add, char **envp);
char			*creat_new_adress(char *str1, char *str2);
char			*supr_adress(char *str1);
char			*add_adress(char *str1, char *str2);
int			find_pwd(char **envp);

/*
** my_strtok.c
*/

char			**my_strtok(char *, char, int);
int			nb_of_words_strtok(char *str, char delim);
void			complete_box_strtok(char *box, char *str, int size, char delim);
char			**my_strtok(char *str, char delim, int start);

/*
** get_next_line.c
*/

char			*get_next_line(int);

#endif
