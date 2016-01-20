/*
** main.c for main in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 10:56:30 2013 levi tabti
** Last update Fri May 24 15:35:05 2013 guillaume lefrant
*/

#include "../../shell.h"

int		exe_all(t_param *params_list, t_shell *sh)
{
  int		*pipe;

  if (params_list->flag_pipe == 0)
    {
      my_execve_fork(*params_list, sh);
      return (0);
    }
  params_list->flag_pipe = FIRST_PIPE;
  pipe = pipes(*params_list, sh);
  params_list = params_list->prev;
  while (params_list && params_list->flag_pipe == 1)
    {
      params_list->flag_pipe = BETWEEN_PIPE;
      pipe = pipes(*params_list, sh, pipe);
      params_list = params_list->prev;
    }
  if (params_list->flag_redir == NOTHING)
    {
      params_list->flag_pipe = END_PIPE;
      pipes(*params_list, sh, pipe);
    }
  else
    red_right(params_list->flag_redir, pipe, "0");
  return (0);
}
