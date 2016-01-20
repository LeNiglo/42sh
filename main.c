/*
** main.c for Minishell2 in /home/lefran_g//Projects/B2/Minishell2
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Wed Feb  6 11:34:32 2013 guillaume lefrant
** Last update Fri May 24 16:48:39 2013 kevin andres
*/

#include	"shell.h"

char		*check_in_path(char **envp, char *exec)
{
  int	i;
  char	**path;

  i = 0;
  while (envp[i] && my_strncmp(envp[i], "PATH", 4) != 0)
    ++i;
  if (!envp[i])
    return ("FAIL");
  path = my_str_word(envp[i], ':', 5, my_strlen(exec));
  i = 0;
  while (path[i])
    {
      my_strcat(path[i], "/");
      my_strcat(path[i], exec);
      if (access(path[i], X_OK) == 0)
	return(path[i]);
      ++i;
    }
  return ("FAIL");
}

int		check_builtins(char **cmd, t_shell *sh)
{
  if (my_strcmp(cmd[0], "exit") == 0)
    exit (1);
  if (my_strcmp(cmd[0], "setenv") == 0)
    {
      if (cmd[1] && cmd[2])
	return (do_setenv(cmd, sh));
      return (0);
    }
  if (my_strcmp(cmd[0], "unsetenv") == 0)
    {
      if (cmd[1])
	return (do_unsetenv(cmd, sh->env));
      return (0);
    }
  if (my_strcmp(cmd[0], "env") == 0)
    return (do_env(sh->env));
  if (my_strcmp(cmd[0], "cd") == 0)
    return (do_cd(cmd, sh->env));
  return (1);
}

int		wait_instructions(t_param exe, char **envp)
{
  char	*path;

  if (my_strcmp((path = check_in_path(envp, exe.cmd[0])), "FAIL")  == 0)
    {
      write(1, exe.cmd[0], my_strlen(exe.cmd[0]));
      write(1, ": Command not found\n", 20);
      return (-1);
    }
  if ((execve(path, exe.cmd , envp)) == -1)
    {
      write(1, exe.cmd[0], my_strlen(exe.cmd[0]));
      write(1, ": Command not found\n", 20);
      return (-1);
    }
  return (0);
}

t_shell		*ini_sh(char **envp)
{
  t_shell	*new;

  if ((new = malloc(sizeof(t_shell))) == NULL)
    exit_null("Error: malloc fail.\n");
  if ((new->env = my_2str_return(envp, 0)) == NULL)
    return (NULL);
  new->status = 0;
  return (new);
}

int		main(int ac, char **av, char **envp)
{
  t_param	*param;
  t_shell	*sh;
  char		*buf;

  if (av[ac - 1] == NULL)
    return (-1);
  if (!envp)
    exit_func("Error: This program need envp.\n");
  if ((sh = ini_sh(envp)) == NULL)
    return (-1);
  while (42)
    {
      aff_prompt("$(USERNAME) ($(PWD)) > ", sh->env);
      if (my_strlen(buf = get_next_line(0)) > 256)
  	my_putstr("File name too long.\n");
      else
  	{
	  if (buf == NULL)
	    exit_malloc();
  	  param = my_classparam(buf);
  	  if (param)
  	    exe_all(param, sh);
  	  free_param(param);
  	}
    }
  return (sh->status);
}
