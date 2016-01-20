/*
** my_str_word.c for 42sh in /afs/epitech.net/users/epitech_2017/lefran_g/public/42SH/Construction
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Tue May 21 14:06:19 2013 kevin andres
** Last update Tue May 21 17:42:05 2013 kevin andres
*/

#include	"shell.h"

char		*remp_str(char *str, char delim, int *pos, int addmot)
{
  int		i;
  char		*dest;

  i = 0;
  if ((dest = malloc((my_strlen(str) + addmot + 1)
		     * sizeof(char))) == NULL)
    return (NULL);
  while (str[*pos] != '\0' && str[*pos] != delim)
    {
      dest[i] = str[*pos];
      ++i;
      ++*pos;
    }
  if (str[*pos] != '\0')
    while (str[*pos] != '\0' && str[*pos] == delim)
      ++*pos;
  dest[i] = '\0';
  return (dest);
}

int		count_word_str(char *str, char delim)
{
  int		i;
  int		max;

  max = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != delim && str[i] != '\0' &&
	  (str[i + 1] == delim || str[i + 1] == '\0'))
	++max;
      ++i;
    }
  return (max);
}

char		**my_str_word(char *str, char delim, int start, int addmot)
{
  char		**dest;
  int		i;
  int		i2;
  int		max;

  i = 0;
  i2 = start;
  max = count_word_str(str, delim);
  if ((dest = malloc((max + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (i < max)
    {
      dest[i] = remp_str(str, delim, &i2, addmot);
      i++;
    }
  dest[i] = 0;
  return (dest);
}
