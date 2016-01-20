/*
** my_execve.c for my_execve in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 07:56:22 2013 levi tabti
** Last update Fri May 24 16:32:10 2013 guillaume lefrant
*/

#include "../../shell.h"

void		my_execve_fork(t_param exe, t_shell *sh)
{
  int	pid;

  if (check_builtins(exe.cmd, sh))
    {
      if ((pid = fork()) == 0)
	wait_instructions(exe, sh->env);
      else
	wait(&(sh->status));
    }
}

void	my_execve(t_param exe, t_shell *sh)
{
  if (check_builtins(exe.cmd, sh))
    wait_instructions(exe, sh->env);
}
