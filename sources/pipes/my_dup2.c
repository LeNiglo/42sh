/*
** my_dup2.c for my_dup2 in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 09:06:07 2013 levi tabti
** Last update Wed May 22 15:16:15 2013 guillaume lefrant
*/

#include "../../shell.h"

void	my_dup2(int fd1, int fd2)
{
  if (dup2(fd1, fd2) == -1)
    {
      write(1, "Error dup2", my_strlen("Error dup2"));
      exit(0);
    }
}
