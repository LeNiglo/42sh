/*
** return_list.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Mon Apr 15 15:23:13 2013 kevin andres
** Last update Wed May 22 15:12:41 2013 guillaume lefrant
*/

#include	"../../shell.h"

int		add_elem_in_list_return(t_param *move, t_param **my_param)
{
  t_param	*new;

  if ((new = malloc(sizeof(t_param))) == NULL)
    return (exit_malloc());
  new->cmd = move->cmd;
  new->end = move->end;
  new->flag_pipe = move->flag_pipe;
  new->flag_redir = move->flag_redir;
  new->file_name = move->file_name;
  new->flag_redir2 = move->flag_redir2;
  new->file_name2 = move->file_name2;
  new->prev = *my_param;
  *my_param = new;
  return (0);
}

t_param		*return_list(t_param *my_param)
{
  t_param	*move;
  t_param	*result;

  move = my_param;
  result = NULL;
  while (move)
    {
      if ((add_elem_in_list_return(move, &result)) == -1)
	return (NULL);
      move = move->prev;
    }
  return (result);
}
