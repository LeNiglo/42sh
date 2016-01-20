/*
** prompt.c for 42sh in /home/moulen_a//Modules/Unix/42sh
**
** Made by axel moulene
** Login   <moulen_a@epitech.net>
**
** Started on  Mon Apr 15 20:03:22 2013 axel moulene
** Last update Wed May 22 15:18:08 2013 guillaume lefrant
*/

#include "../../shell.h"

char	*get_sub_str(char *src, int start, int end)
{
  int	i;
  char	*tmp;

  if (!(tmp = malloc(end - start + 1)))
    return (NULL);
  i = 0;
  while (i + start < end)
    {
      tmp[i] = src[i + start];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

int	print_var(char **env, char *var)
{
  int	i;
  char	*tmp;
  int	len;

  len = strlen(var);
  i = 0;
  while (env[i])
    {
      if (!(strncmp(env[i], var, len)) && env[i][len] == '=')
        {
          if (!(tmp = get_sub_str(env[i], len + 1, strlen(env[i]))))
	    return (0);
	  write(1, tmp, strlen(tmp));
          return (1);
        }
      i++;
    }
  return (0);
}

int	get_data(char *str, int start, char **envp)
{
  int	i;
  char	*tmp;

  i = start + 2;
  while (str[i] != ' ' && str[i])
    {
      if (str[i] ==  ')')
	{
	  if (!(tmp = get_sub_str(str, start + 2, i)))
	    return (start);
	  if (!(print_var(envp, tmp)))
	    return (start);
	  return (i + 1);
	}
      i++;
    }
  return (start);
}

void	aff_prompt(char *prompt, char **envp)
{
  int	i;

  i = 0;
  while (prompt[i])
    {
      if (prompt[i] == '$' && prompt[i + 1] == '(')
	i = get_data(prompt, i, envp);
      write(1, &prompt[i], 1);
      i++;
    }
}
