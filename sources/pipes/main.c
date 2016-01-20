/*
** main.c for main in /home/tabti_l//project/unix/42sh
** 
** Made by levi tabti
** Login   <tabti_l@epitech.net>
** 
** Started on  Thu Apr  4 10:56:30 2013 levi tabti
** Last update Fri May 24 15:40:20 2013 levi tabti
*/

#include <stdio.h>
#include <stdlib.h>
#include "pipe.h"
#include "red.h"

void		new_param(t_param **params, t_param exe)
{
  t_param	*change;

  change = malloc(sizeof(t_param));
  change->cmd = exe.cmd;
  change->flag_pipe = exe.flag_pipe;
  change->flag_redir = exe.flag_redir;
  change->prev = *params;
  *params = change;
}

int		check_end_list(t_param *params_list)
{
  if (params_list == NULL)
    return (0);
  else
    if (params_list->flag_pipe == 0)
      return (0);
    else
      return (1);
}

int		exe_all(t_param *params_list)
{
  int		*pipe;

  if (params_list->flag_pipe == 0)
      /*execve qui fork*/
  if ((pipe = first_pipe(*params_list)) == NULL)
    return (-1);
  params_list = params_list->prev;
  while (check_end_list(params_list))
    {
      if ((pipe = between_pipe(*params_list, pipe)) == NULL)
	return (-1);
      params_list = params_list->prev;
    }
  if (params_list->flag_redir == NOTHING)
    {
      if (end_pipe(*params_list, pipe) == NULL)
	return (-1);
    }
  else
    {
      if ((pipe = between_pipe(*params_list, pipe)) == NULL)
	return (-1);
      red_right(params_list->flag_redir, pipe, "0");
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_param	exe;
  t_param	*params_list;

  params_list = NULL;
  
  av[5] = NULL;
  exe.cmd = &av[3];
  exe.flag_redir = 0;
  exe.flag_pipe = 0;
  exe.file_name = "0";
  new_param(&params_list, exe);
  
  av[5] = NULL;
  exe.cmd = &av[3];
  exe.flag_pipe = 1;
  new_param(&params_list, exe);

  av[2] = NULL;
  exe.cmd = &av[1];
  exe.flag_pipe = 1;
  new_param(&params_list, exe);

  printf("%d", exe_all(params_list));
  return (0);
}
