/*
** pipes.c for pipes in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 07:41:58 2013 levi tabti
** Last update Wed May 22 15:15:16 2013 guillaume lefrant
*/

#include <stdarg.h>
#include "../../shell.h"

int		*first_pipe(t_param exe, t_shell *sh)
{
  int		*pipe_next;
  int		pid;

  pipe_next = malloc(2 * sizeof(int));
  my_pipe(pipe_next);
  pid = my_fork();
  if (pid == 0)
    {
      close(pipe_next[0]);
      my_dup2(pipe_next[1], 1);
      my_execve(exe, sh);
    }
  close(pipe_next[1]);
  return (pipe_next);
}

int		*between_pipe(t_param exe, int pipe_pre[2], t_shell *sh)
{
  int		*pipe_next;
  int		pid;

  pipe_next = malloc(2 * sizeof(int));
  my_pipe(pipe_next);
  pid = my_fork();
  if (pid == 0)
    {
      close(pipe_next[0]);
      my_dup2(pipe_next[1], 1);
      my_dup2(pipe_pre[0], 0);
      my_execve(exe, sh);
    }
  close(pipe_next[1]);
  free(pipe_pre);
  return (pipe_next);
}

void		end_pipe(t_param exe, int pipe_pre[2], t_shell *sh)
{
  int		pid;

  pid = my_fork();
  if (pid == 0)
    {
      my_dup2(pipe_pre[0], 0);
      my_execve(exe, sh);
    }
  free(pipe_pre);
}

int		*pipes(t_param exe, t_shell *sh, ...)
{
  va_list	ap;
  int		*pipe;

  va_start(ap, sh);
  if (exe.flag_pipe == FIRST_PIPE)
    return (first_pipe(exe, sh));
  else if (exe.flag_pipe == BETWEEN_PIPE)
    {
      pipe = between_pipe(exe, va_arg(ap, int*), sh);
      va_end(ap);
      return (pipe);
    }
  else if (exe.flag_pipe == END_PIPE)
    {
      end_pipe(exe, va_arg(ap, int*), sh);
      va_end(ap);
      return (NULL);
    }
  return (0);
}
