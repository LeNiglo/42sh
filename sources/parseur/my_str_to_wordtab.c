/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/andres_k//0.file/file/file.lib
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Sun Mar 10 21:33:58 2013 kevin andres
** Last update Wed May 22 15:12:57 2013 guillaume lefrant
*/

#include	"../../shell.h"

char		*remp_tab(char *str, char *delim, int *pos)
{
  int		i;
  char		*dest;

  i = 0;
  if ((dest = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[*pos] != '\0' && verif_word(str[*pos]) == 0 &&
	 verif_delim(str[*pos], delim) == 0)
    {
      dest[i] = str[*pos];
      ++i;
      ++*pos;
    }
  if (str[*pos] != '\0')
    while (str[*pos] != '\0' && verif_word(str[*pos]) == -1)
      ++*pos;
  dest[i] = '\0';
  return (dest);
}

char		*recup_inst(char *str, char *delim, int *pos)
{
  int		i;
  char		*dest;

  i = 0;
  if ((dest = malloc(my_strlen(str) * sizeof(char))) == NULL)
    return (NULL);
  while(str[*pos] != '\0' &&
	(verif_delim(str[*pos], delim) == -1 || verif_word(str[*pos]) == -1))
    {
      if (verif_delim(str[*pos], delim) == -1)
	{
	  dest[i] = str[*pos];
	  i++;
	}
      ++*pos;
    }
  dest[i] = '\0';
  return (dest);
}

char		**my_str_to_wordtab(char *str, char *delim, int *count)
{
  char		**dest;
  int		i;
  int		i2;
  int		max;

  i = 0;
  i2 = *count;
  max = count_wordelim(str, delim, i2);
  if ((dest = malloc((max + 1)* sizeof(char *))) == NULL)
    return (NULL);
  while (i < max)
    {
      if ((dest[i] = remp_tab(str, delim, &i2)) == NULL)
	return (NULL);
      i++;
      if (verif_delim(str[i2], delim) == -1)
	{
	  if ((dest[i] = recup_inst(str, delim, &i2)) == NULL)
	      return (NULL);
	  i++;
	}
    }
  *count = i2;
  dest[i] = 0;
  return (dest);
}
