/*
** change_env.c for 42sh in /afs/epitech.net/users/epitech_2017/lefran_g/public/42SH/Construction
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Tue May 14 11:00:04 2013 kevin andres
** Last update Tue May 21 16:18:45 2013 guillaume lefrant
*/

#include	"shell.h"

int		find_pwd(char **envp)
{
  int		i;

  i = 0;
  while (envp[i])
    {
      if (my_strncmp(envp[i], "PWD", 3) == 0)
	return (i);
      ++i;
    }
  exit_func("Error: PWD doesn't exist in PATH.\n");
  return (0);
}

char		*creat_new_adress(char *str1, char *str2)
{
  char		*dest;

  if (my_str_compar(str2, "..") == 1)
    dest = supr_adress(str1);
  else if (str2[0] == '/')
    dest = my_str_add("PWD=", str2);
  else
    dest = add_adress(str1, str2);
  return (dest);
}

char		*supr_adress(char *str1)
{
  int		i;

  i = my_strlen(str1);
  while (str1[i] != '/' && i > 0)
    --i;
  str1[i] = '\0';
  return (str1);
}

char		*add_adress(char *str1, char *str2)
{
  char		*dest;
  int		i;
  int		i2;

  i2 = 0;
  i = 0;
  if ((dest = malloc((my_strlen(str1) + my_strlen(str2) + 2)
		     * sizeof(char))) == NULL)
    return (NULL);
  while (str1[i] != '\0')
    {
      dest[i2] = str1[i];
      ++i2;
      ++i;
    }
  dest[i2++] = '/';
  i = 0;
  while (str2[i] != '\0')
    {
      dest[i2] = str2[i];
      ++i2;
      ++i;
    }
  dest[i2] = '\0';
  return (dest);
}

char		**change_env(char *add, char **envp)
{
  int		i;
  char		*temp;

  if ((i = find_pwd(envp)) == -1)
    return (envp);
  if ((temp = creat_new_adress(envp[i], add)) != NULL)
    envp[i] = temp;
  return (envp);
}
