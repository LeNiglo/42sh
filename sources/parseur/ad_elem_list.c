/*
** ad_elem_list.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Fri Apr 12 15:46:08 2013 kevin andres
** Last update Wed May 22 15:14:09 2013 guillaume lefrant
*/

#include	"../../shell.h"

int		add_elem_in_list(char **data, t_param **my_param,
				 t_conf *my_value)
{
  t_param	*new;
  int		inst;
  int		mode;

  if ((new = malloc(sizeof(t_param))) == NULL)
    return (exit_malloc());
  ini_struct(new);
  if (my_value->save == 1)
    return (exit_func("Ambiguous output redirect.\n"));
  if (verif_delim_exist(data, DELIM) == 1)
    {
      inst = my_2strlen(data) - 1;
      if ((mode = verif_error_inst(data[inst])) == -1)
	return (-1);
      else if (mode == 2)
	my_value->save = 1;
      if ((mode = find_instruction(data[inst])) == -1)
	return (-1);
      if ((remp_struct_with_inst(mode, new, my_value)) == -1)
      	return (-1);
      if (data != NULL)
	data[inst] = 0;
    }
  new->cmd = data;
  new->prev = *my_param;
  *my_param = new;
  return (0);
}
