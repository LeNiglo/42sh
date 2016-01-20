/*
** my_pipe.c for my_pipe in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 07:43:12 2013 levi tabti
** Last update Wed May 22 15:15:47 2013 guillaume lefrant
*/

#include "../../shell.h"

void	my_pipe(int pipefd[2])
{
  if (pipe(pipefd) == -1)
    {
      write(1, "Error pipe", my_strlen("Error pipe"));
      exit(0);
    }
}
