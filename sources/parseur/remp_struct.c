/*
** remp_struct.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Mon Apr 15 12:55:14 2013 kevin andres
** Last update Wed May 22 15:12:49 2013 guillaume lefrant
*/

#include	"../../shell.h"

void		ini_struct(t_param *new)
{
  new->end = 0;
  new->flag_pipe = 0;
  new->flag_redir = 0;
  new->flag_redir2 = 0;
  new->cmd = NULL;
  new->file_name = NULL;
  new->file_name2 = NULL;
}

int		find_size_file(t_conf *cmd)
{
  int		nb;
  int		i;

  i = cmd->pos;
  nb = 0;
  while (cmd->string_cmd[i] != '\0' && verif_word(cmd->string_cmd[i]) == -1)
    ++i;
  while (cmd->string_cmd[i] != '\0' && verif_word(cmd->string_cmd[i]) == 0 &&
	 verif_delim(cmd->string_cmd[i], DELIM) == 0)
    {
      ++i;
     ++nb;
    }
  return (nb);
}

char		*my_get_name(t_conf *cmd)
{
  char		*dest;
  int		i;
  int		i2;

  i2 = 0;
  i = cmd->pos;
  if ((dest = malloc(find_size_file(cmd) + 1 * sizeof(char))) == NULL)
    return (NULL);
  while (cmd->string_cmd[i] != '\0' && verif_word(cmd->string_cmd[i]) == -1)
    ++i;
  while (cmd->string_cmd[i] != '\0' && verif_word(cmd->string_cmd[i]) == 0 &&
	 verif_delim(cmd->string_cmd[i], DELIM) == 0)
    {
      dest[i2] = cmd->string_cmd[i];
      ++i;
      ++i2;
    }
  dest[i2] = '\0';
  if (i2 == 0)
    return (NULL);
  cmd->pos = i;
  return (dest);
}

int		name_exist(t_conf *cmd)
{
  int		i;
  int		i2;

  i2 = 0;
  i = cmd->pos;
  while (cmd->string_cmd[i] != '\0' && verif_word(cmd->string_cmd[i]) == -1)
    ++i;
  while (cmd->string_cmd[i] != '\0' && verif_word(cmd->string_cmd[i]) == 0 &&
	 verif_delim(cmd->string_cmd[i], DELIM) == 0)
    {
      ++i;
      ++i2;
    }
  if (i2 == 0)
    return (-1);
  return (0);
}

int		remp_struct_with_inst(int mode, t_param *new, t_conf *cmd)
{
  int		verif;

  ini_struct(new);
  if (mode == 6 || mode == 7 || mode == 8 || mode == 9)
    {
      cmd->check_end = mode;
      if ((mode == 6 || mode == 8) && name_exist(cmd) == -1)
	return (exit_func("Invalid null command.\n"));
    }
  else if (mode == 1 || mode == 2 || mode == 3 || mode == 4)
    {
      new->flag_redir = mode;
      if ((new->file_name = my_get_name(cmd)) == NULL)
	return (exit_func("Missing name for redirect.\n"));
      while ((verif = check_next_inst(cmd, new, mode)) != -2)
	if (verif == -1)
	  return (-1);
    }
  else
    {
      new->flag_pipe = 1;
      if (name_exist(cmd) == -1)
	return (exit_func("Invalid null command.\n"));
    }
  return (0);
}
