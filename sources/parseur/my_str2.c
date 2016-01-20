/*
** my_str2.c for 42sh in /afs/epitech.net/users/epitech_2017/lefran_g/public/42SH/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Wed May 15 12:25:45 2013 kevin andres
** Last update Wed May 22 15:13:11 2013 guillaume lefrant
*/

#include	"../../shell.h"

char		*my_str_supr(char *str1, char *str2)
{
  char		*dest;
  int		i;
  int		i2;

  i = 0;
  i2 = 0;
  if ((dest = malloc((my_strlen(str2) - my_strlen(str1) + 1))) == NULL)
    exit_malloc();
  while (str2[i] && str1[i] && str2[i] == str1[i])
    ++i;
  while (str2[i] != '\0')
    {
      dest[i2] = str2[i];
      ++i2;
      ++i;
    }
  dest[i2] = '\0';
  return (dest);
}

char		**my_2str_return(char **src, int add)
{
  char		**dest;
  int		i;
  int		max;

  max = my_2strlen(src);
  i = 0;
  if ((dest = malloc((max + 1 + add) * sizeof(char*))) == NULL)
    exit_null("Error: malloc fail.\n");
  while (i < max)
    {
      dest[i] = my_str_return(src[i]);
      ++i;
    }
  dest[i] = NULL;
  return (dest);
}
