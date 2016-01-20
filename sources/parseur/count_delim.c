/*
** count_delim.c for 107transfert in /home/andres_k//0file/projet/math/107transfert/work/file.lib
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Thu Mar  7 11:53:41 2013 kevin andres
** Last update Wed May 22 15:14:00 2013 guillaume lefrant
*/

#include	"../../shell.h"

int	verif_delim(char caract, char *delim)
{
  int	i;

  i = 0;
  while (delim[i] != '\0')
    {
      if (caract == delim[i])
	return (-1);
      ++i;
    }
  return (0);
}

int	verif_word(char caract)
{
  if (caract == ' ' || caract == '\t')
    return (-1);
  else
    return (0);
}

int	count_wordelim(char *str, char *delim, int i)
{
  int	nb;

  nb = 0;
  while (str[i] != '\0' && verif_delim(str[i], delim) == 0)
    {
      if (verif_word(str[i]) == -1 && str[i + 1] != '\0' &&
	  verif_word(str[i + 1]) == 0 && verif_delim(str[i + 1], delim) == 0)
	nb++;
      i++;
    }
  if (str[i] != '\0' && verif_delim(str[i], delim) == -1)
    nb++;
  return (nb + 1);
}
