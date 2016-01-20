/*
** my_strcat.c for my_strcat in /home/lefran_g//D7
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Wed Oct 10 17:39:45 2012 guillaume lefrant
** Last update Tue May 21 13:56:23 2013 kevin andres
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    ++i;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      ++i;
      ++j;
    }
  dest[i] = '\0';
  return (dest);
}
