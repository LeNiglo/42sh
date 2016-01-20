/*
** my_fork.c for my_fork in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 07:50:33 2013 levi tabti
** Last update Wed May 22 15:15:55 2013 guillaume lefrant
*/

#include "../../shell.h"

int	my_fork()
{
  int	pid;

  if ((pid = fork()) == -1)
    {
      write(1, "Error fork", my_strlen("Error fork"));
      exit(0);
    }
  return (pid);
}
