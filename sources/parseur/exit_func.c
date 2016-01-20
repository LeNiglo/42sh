/*
** fail_malloc.c for 42sh in /u/all/lefran_g/public/42SH/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Tue Apr  9 16:25:13 2013 kevin andres
** Last update Wed May 22 15:13:49 2013 guillaume lefrant
*/

#include	"../../shell.h"

void		my_putstr_fail(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
}

int		exit_malloc()
{
  my_putstr_fail("Error : malloc fail.\n");
  return (-1);
}

char		*exit_null(char *str)
{
  my_putstr_fail(str);
  return (NULL);
}

int		exit_func(char *str)
{
  my_putstr_fail(str);
  return (-1);
}

char		**exit_2char(char **dest, char *str)
{
  my_putstr_fail(str);
  return (dest);
}
