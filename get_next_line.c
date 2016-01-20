/*
** get_next_line.c for get_next_line in /home/lefran_g//Projects/GetNexLine
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Mon Nov 19 10:19:13 2012 guillaume lefrant
** Last update Tue May 21 18:23:28 2013 guillaume lefrant
*/

#include	"shell.h"

char		*get_next_line(const int fd)
{
  static char	buffer[CHAR_READ + 1];
  static int	ret;
  char		*s;
  int		i;

  i = 0;
  s = malloc(CHAR_READ + 1);
  if (s == 0)
    return (NULL);
  ret = read(fd, buffer, CHAR_READ);
  if (ret <= 0)
    return (NULL);
  if (buffer[i] == 0)
    return (NULL);
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      s[i] = buffer[i];
      ++i;
    }
  s[i] = '\0';
  buffer[i] = '\0';
  return (s);
}
