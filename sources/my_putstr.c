/*
** my_putstr.c for my_putstr in /home/lefran_g//Projects/Printf
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Thu Nov  8 15:01:49 2012 guillaume lefrant
** Last update Tue May 21 18:30:15 2013 kevin andres
*/

#include "../shell.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_put2str(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putstr(str[i]);
      my_putchar('\n');
      ++i;
    }
}
