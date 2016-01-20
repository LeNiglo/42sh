/*
** modif_setenv.c for 42sh in /u/all/lefran_g/public/42SH/Construction
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Tue May 21 15:33:57 2013 kevin andres
** Last update Tue May 21 20:25:04 2013 kevin andres
*/

#include	"shell.h"

char		**add_elem_envp(char **envp, char *new)
{
  char		**dest;
  int		i;

  i = 0;
  if ((dest = my_2str_return(envp, 1)) == NULL)
    {
      my_putstr_fail("Error: malloc fail.\n");
      return (NULL);
    }
  while (dest[i])
    ++i;
  dest[i] = new;
  ++i;
  dest[i] = NULL;
  free_doble_char(envp);
  return (dest);
}
