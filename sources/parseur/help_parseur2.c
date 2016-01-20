/*
** help_parseur2.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Wed Apr 17 11:27:49 2013 kevin andres
** Last update Wed May 22 15:13:28 2013 guillaume lefrant
*/

#include	"../../shell.h"

int		find_size_inst(t_conf *cmd)
{
  int		i;
  int		i2;

  i2 = 0;
  i = cmd->pos;
  while (cmd->string_cmd[i] != '\0' &&
	 (verif_word(cmd->string_cmd[i]) == -1 ||
	  verif_delim(cmd->string_cmd[i], DELIM) == -1))
    {
      if (verif_word(cmd->string_cmd[i]) == 0)
	++i2;
      ++i;
    }
  return (i2);
}

char		*find_next_inst(t_conf *cmd)
{
  char		*dest;
  int		i2;
  int		i;

  i = cmd->pos;
  i2 = 0;
  if ((dest = malloc(find_size_inst(cmd) + 1)) == NULL)
    return (NULL);
   while (cmd->string_cmd[i] != '\0' &&
	 (verif_word(cmd->string_cmd[i]) == -1 ||
	  verif_delim(cmd->string_cmd[i], DELIM) == -1))
    {
      if (verif_word(cmd->string_cmd[i]) == 0)
	{
	  dest[i2] = cmd->string_cmd[i];
	  ++i2;
	}
      ++i;
    }
   cmd->pos = i;
   dest[i2] = '\0';
   if (i2 == 0 || verif_error_inst(dest) == -1)
     return (NULL);
   return (dest);
}

int		check_next_inst(t_conf *cmd, t_param *new, int mode)
{
  char		*inst;
  int		newmode;

  if ((inst = find_next_inst(cmd)) == NULL)
    return (-2);
  if (((mode == 1 || mode == 2) && inst[0] == '>')
      || ((mode == 3 || mode == 4) && inst[0] == '<'))
    return (exit_func("Ambiguous input redirect.\n"));
  else if ((mode == 1 || mode == 2) && inst[0] == '<')
    cmd->save = 0;
  if ((newmode = find_instruction(inst)) == -1)
    return (-1);
  if (inst[0] == '<' || inst[0] == '>')
    {
      free(inst);
      if ((next_inst_redir(new, cmd, newmode)) == -1)
	return (-1);
    }
  else
    {
      free(inst);
      if ((next_inst_other(new, cmd, newmode)) == -1)
	return (-1);
    }
  return (0);
}

int		next_inst_redir(t_param *new, t_conf *cmd, int mode)
{
  cmd->nb_redir = cmd->nb_redir + 1;
  if (cmd->nb_redir >= 2)
    return (exit_func("Ambiguous output redirect.\n"));
  new->flag_redir2 = mode;
  if ((new->file_name2 = my_get_name(cmd)) == NULL)
    return (exit_func("Missing name for redirect.\n"));
  return (0);
}

int		next_inst_other(t_param *new, t_conf *cmd, int mode)
{
  if (mode == 6 || mode == 7 || mode == 8 || mode == 9)
    {
      cmd->check_end = mode;
      if (mode == 6 && name_exist(cmd) == -1)
	return (exit_func("Invalid null command.\n"));
    }
  else
    {
      new->flag_pipe = 1;
      if (name_exist(cmd) == -1)
	return (exit_func("Invalid null command.\n"));
    }
  return (0);
}
