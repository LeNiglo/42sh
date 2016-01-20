/*
** free_all.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Wed Apr 17 20:25:42 2013 kevin andres
** Last update Wed May 22 15:13:42 2013 guillaume lefrant
*/

#include	"../../shell.h"

void		free_list(t_param *my_param, t_conf *cmd)
{
  if (cmd->string_cmd)
    free(cmd->string_cmd);
  if (cmd)
    free(cmd);
  free_struct(my_param);
}

void		free_struct(t_param *my_param)
{
  t_param	*tmp;

  while (my_param)
    {
      tmp = my_param;
      my_param = my_param->prev;
      if (tmp)
	free(tmp);
    }
}

void		free_param(t_param *param)
{
  t_param	*next;

  next = NULL;
  while (param != NULL)
    {
      next = param->prev;
      if (param->file_name)
	free(param->file_name);
      if (param->file_name2)
	free(param->file_name2);
      if (param->cmd)
	free_doble_char(param->cmd);
      if (param)
	free(param);
      param = next;
    }
}

void		free_doble_char(char **src)
{
  int		i;

  i = 0;
  while (src[i] != NULL && src[i] != '\0')
    {
      if (src[i])
	free(src[i]);
      ++i;
    }
  if (src)
    free(src);
}
