/*
** env_cd.c for minishell in /home/lefran_g//Projects/Minishell
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Tue Dec 18 13:21:52 2012 guillaume lefrant
** Last update Tue May 21 20:03:10 2013 kevin andres
*/

#include	"shell.h"

int		do_setenv(char **cmd, t_shell *sh)
{
  int		i;
  char		*new;
  char		*new2;

  i = -1;
  while (sh->env[++i] && my_strncmp(sh->env[i], cmd[1], my_strlen(cmd[1])));
  new = my_str_add(cmd[1], "=");
  new2 = my_str_add(new, cmd[2]);
  free(new);
  if (!sh->env[i])
    sh->env = add_elem_envp(sh->env, new2);
   else
    sh->env[i] = new2;
  return (0);
}

int		do_unsetenv(char **cmd, char **envp)
{
  int		i;

  i = 0;
  while (envp[i] && my_strncmp(envp[i], cmd[1], my_strlen(cmd[1])))
    ++i;
  while (envp[i])
    {
      envp[i] = envp[i + 1];
      ++i;
    }
  return (0);
}

int		do_env(char **envp)
{
  my_put2str(envp);
  return (0);
}

char		**help_do_cd(char **foo, char **envp)
{
  int		i;

  i = 0;
  if (foo[1])
    {
      if (chdir(foo[1]) == -1)
	printf("%s: No such file or directory\n", foo[1]);
      else
	envp = change_env(foo[1], envp);
    }
  else
    {
      while (envp[i] && my_strncmp(envp[i], "HOME=", 5) != 0)
	++i;
      if (!envp[i])
	exit_2char(envp, "Error: HOME doesn't exit in PATH.\n");
      if (chdir(&envp[i][5]) == -1)
	printf("%s: No such file or directory\n", &envp[i][5]);
      else
	envp[find_pwd(envp)] = my_str_add("PWD=", &envp[i][5]);
    }
  return (envp);
}

int		do_cd(char **foo, char **envp)
{
  static char  	*dir;
  char		*temp;

  if (foo[1] && my_str_compar(foo[1], "-") == 1 && dir != NULL)
    {
      if (chdir(dir) == -1)
	printf("%s: No such file or directory\n", foo[1]);
      else
	{
	  temp = my_str_supr("PWD=", envp[find_pwd(envp)]);
	  envp[find_pwd(envp)] = my_str_add("PWD=", dir);
	  dir = temp;
	}
    }
  else
    {
      dir = my_str_supr("PWD=", envp[find_pwd(envp)]);
      envp = help_do_cd(foo, envp);
    }
  return (0);
}
