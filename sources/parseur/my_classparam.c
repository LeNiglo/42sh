/*
** my_classparam.c for 42sh in /u/all/lefran_g/public/42SH/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Tue Apr  9 16:06:19 2013 kevin andres
** Last update Wed May 22 15:13:19 2013 guillaume lefrant
*/

#include	"../../shell.h"

t_conf		*ini_value(char *caract)
{
  t_conf	*ini_value;

  if ((ini_value = malloc(1 * sizeof(t_conf))) == NULL)
    return (NULL);
  ini_value->string_cmd = my_str_return(caract);
  ini_value->pos = 0;
  while (caract[ini_value->pos] == ' ')
    ++ini_value->pos;
  ini_value->nb_redir = 0;
  ini_value->save = 0;
  ini_value->check_end = 0;
  return (ini_value);
}

int		add_end_inst(t_param **my_param, t_conf *my_value)
{
  t_param	*new;

  if ((new = malloc(sizeof(t_param))) == NULL)
    return (exit_malloc());
  ini_struct(new);
  new->end = my_value->check_end;;
  new->prev = *my_param;
  *my_param = new;
  my_value->check_end = 0;
  return (0);
}

t_param		*my_classparam(char *cmd)
{
  t_param	*my_param;
  t_param	*my_result;
  t_conf	*my_value;
  char		**buff;

  buff = NULL;
  my_param = NULL;
  my_value = ini_value(cmd);
  while (cmd[my_value->pos] != '\0' || my_value->check_end != 0)
    {
      if (my_value->check_end != 0)
	{
	  if ((add_end_inst(&my_param, my_value)) == -1)
	    return (NULL);
	}
      else
      	{
	  buff = my_str_to_wordtab(my_value->string_cmd, DELIM, &my_value->pos);
	  if ((add_elem_in_list(buff, &my_param, my_value)) == -1)
	    return (NULL);
	}
    }
  my_result = return_list(my_param);
  free_list(my_param, my_value);
  return (my_result);
}
