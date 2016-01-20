/*
** my_strcmp.c for my_strcmp in /home/lefran_g//D6
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Mon Oct  8 15:26:14 2012 guillaume lefrant
** Last update Sun Dec 30 18:09:43 2012 guillaume lefrant
*/

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}
