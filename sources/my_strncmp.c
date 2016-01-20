/*
** my_strncmp.c for my_strncmp in /home/lefran_g//D6
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Mon Oct  8 15:45:26 2012 guillaume lefrant
** Last update Sun Dec 30 18:09:08 2012 guillaume lefrant
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n && s1[i] == s2[i])
    ++i;
  if (i == n)
    return (0);
  return (s1[i] - s2[i]);
}
