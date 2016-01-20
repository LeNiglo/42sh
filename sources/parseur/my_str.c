/*
** my_strlen.c for my_strlen in /home/andres_k//afs/jour04/exo3
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Thu Oct  4 16:33:31 2012 kevin andres
** Last update Wed May 22 15:13:04 2013 guillaume lefrant
*/

#include	"../../shell.h"

int		my_strlen(char *str)
{
  int		c;

  c = 0;
  while (str[c] != '\0')
    c = c + 1;
  return (c);
}

int		my_2strlen(char **str)
{
  int		c;

  c = 0;
  while (str[c])
    c = c + 1;
  return (c);
}

int		my_str_compar(char *stra, char *strb)
{
  int		i;

  i = 0;
  if (my_strlen(stra) != my_strlen(strb))
    return (-1);
  while (stra[i] != '\0')
    {
      if (stra[i] != strb[i])
	return (-1);
      i++;
    }
  if (strb[i] != '\0')
    return (-1);
  return (1);
}

char		*my_str_return(char *src)
{
  char		*dest;
  int		i;

  i = 0;
  if ((dest = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_str_add(char *str1, char *str2)
{
  char		*dest;
  int		i;
  int		i2;

  i2 = 0;
  i = 0;
  if (str2 && str2[my_strlen(str2) - 1] == '/')
    str2[my_strlen(str2) - 1] = '\0';
  if ((dest = malloc(my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str1[i] != '\0')
    {
      dest[i2] = str1[i];
      ++i;
      ++i2;
    }
  i = 0;
  while (str2[i] != '\0')
    {
      dest[i2] = str2[i];
      ++i;
      ++i2;
    }
  dest[i2] = '\0';
  return (dest);
}
