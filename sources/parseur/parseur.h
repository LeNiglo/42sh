/*
** parseur.h for 42sh in /u/all/lefran_g/public/42SH/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Tue Apr  9 16:06:41 2013 kevin andres
** Last update Tue May 21 18:04:09 2013 kevin andres
*/

#ifndef	PARSEUR_H_
# define PARSEUR_H_

# define	DELIM	";&|><"

typedef	struct		s_param
{
  int			end;
  int			flag_pipe;
  int			flag_redir;
  int			flag_redir2;
  char			*file_name;
  char			*file_name2;
  char			**cmd;
  struct s_param	*prev;
}			t_param;

typedef	struct		s_conf
{
  char			*string_cmd;
  int			pos;
  int			check_end;
  int			save;
  int			nb_redir;
}			t_conf;

/*
** my_str_to_wordtab.c
*/

char			**my_str_to_wordtab(char *str, char *delim, int *count);
char			*remp_tab(char *str, char *delim, int *pos);

/*
** my_classparam.c
*/

t_param			*my_classparam(char *cmd);
t_conf			*ini_value(char *caract);
int			add_end_inst(t_param **my_param, t_conf *my_value);
void			my_show_list(t_param *my_param);

/*
** return_list.c
*/

t_param			*return_list(t_param *my_param);
int			add_elem_in_list_return(t_param *move, t_param **my_param);

/*
** ad_elem_list.c
*/

int			add_elem_in_list(char **data, t_param **my_param, t_conf *my_value);

/*
** exit_func.c
*/

int			exit_malloc();
int			exit_func(char *str);
char			*exit_null(char *str);
void			my_putstr_fail(char *str);
char			**exit_2char(char **dest, char *str);

/*
** count_delim.c
*/

int			count_wordelim(char *str, char *delim, int i);
int			verif_word(char caract);
int			verif_delim(char caract, char *delim);

/*
** help_parseur1.c
*/

int			find_instruction(char *inst);
int			verif_error_inst(char *data);
int			error_except(char *data);
int			verif_delim_exist(char **data, char *delim);
char			**creat_all_inst();

/*
** help_parseur2.c
*/

char			*find_next_inst(t_conf *cmd);
int			find_size_inst(t_conf *cmd);
int			check_next_inst(t_conf *cmd, t_param *new, int mode);
int			next_inst_other(t_param *new, t_conf *cmd, int mode);
int			next_inst_redir(t_param *new, t_conf *cmd, int mode);

/*
** remp_struct.c
*/

int			name_exist(t_conf *);
int			remp_struct_with_inst(int mode, t_param *new, t_conf *cmd);
int			find_size_file(t_conf *cmd);
void			ini_struct(t_param *new);
char			*my_get_name(t_conf *cmd);

/*
** free_all.c
*/

void			free_doble_char(char **src);
void			free_list(t_param *my_param, t_conf *cmd);
void			free_param(t_param *);
void			free_struct(t_param *);

/*
** my_str.c
*/

int			my_strlen(char *str);
int			my_2strlen(char **str);
int			my_str_compar(char *stra, char *strb);
char			*my_str_return(char *src);
char			*my_str_add(char *str1, char *str2);

/*
** my_str2.c
*/

char			*my_str_supr(char *str1, char *str2);
char			**my_2str_return(char **src, int add);

#endif
