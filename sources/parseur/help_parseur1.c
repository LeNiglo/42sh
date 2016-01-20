/*
** help_parseur1.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Fri Apr 12 15:52:44 2013 kevin andres
** Last update Wed May 22 15:13:35 2013 guillaume lefrant
*/

#include	"../../shell.h"

int		verif_delim_exist(char **data, char *delim)
{
  int		i;

  i = 0;
  while (data[i] != '\0')
    {
      if (verif_delim(data[i][0], delim) == -1)
	return (1);
      i++;
    }
  return (0);
}

int		error_except(char *data)
{
  if (my_str_compar(data, "||") == 1)
    return (1);
  if (my_str_compar(data, ">>") == 1)
    return (1);
  if (my_str_compar(data, "<<") == 1)
    return (1);
  if (my_str_compar(data, "&&") == 1)
    return (1);
  return (-1);
}

int		verif_error_inst(char *data)
{
  int		max;

  max = my_strlen(data);
  if (max >= 2)
    if (error_except(data) == -1)
      return (exit_func("Invalid null command.\n"));
  if (data[0] == '>')
    return (2);
  return (0);
}

char		**creat_all_inst()
{
  char		**all_inst;

  if ((all_inst = malloc(11 * sizeof(char*))) == NULL)
    return (NULL);
  all_inst[0] = my_str_return("START");
  all_inst[1] = my_str_return(">");
  all_inst[2] = my_str_return(">>");
  all_inst[3] = my_str_return("<");
  all_inst[4] = my_str_return("<<");
  all_inst[5] = my_str_return("|");
  all_inst[6] = my_str_return("||");
  all_inst[7] = my_str_return("&");
  all_inst[8] = my_str_return("&&");
  all_inst[9] = my_str_return(";");
  all_inst[10] = NULL;
  return (all_inst);
}

int		find_instruction(char *inst)
{
  char		**all_inst;
  int		i;

  i = 0;
  if ((all_inst = creat_all_inst()) == NULL)
    return (-1);
  while (all_inst[i] != NULL)
    {
      if (my_str_compar(inst, all_inst[i]) == 1)
	{
	  free_doble_char(all_inst);
	  return (i);
	}
      ++i;
    }
  free_doble_char(all_inst);
  return (-1);
}
