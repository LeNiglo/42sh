/*
** red.c for red in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 10:57:53 2013 levi tabti
** Last update Wed May 22 15:15:08 2013 guillaume lefrant
*/

#include	"../../shell.h"

void		red_right(int flag, int pipe_pre[2], char *file_name)
{
  int		fd;
  int		size;
  char		buff[257];

  if (flag == RED_SIMPLE_RIGHT)
    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  else if (flag == RED_DOUBLE_RIGHT)
    {
      fd = open(file_name, O_WRONLY | O_APPEND);
      if (fd == -1)
	red_right(RED_SIMPLE_RIGHT, pipe_pre, file_name);
    }
  if (fd != -1)
    {
      while ((size = read(pipe_pre[0], buff, 256)) != 0)
	{
	  buff[size] = '\0';
	  write(fd, buff, size);
	}
    }
}
