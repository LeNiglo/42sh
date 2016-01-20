/*
** useless.c for 42sh in /home/andres_k//0.file/projet/linux/42sh/parseur
**
** Made by kevin andres
** Login   <andres_k@epitech.net>
**
** Started on  Mon Apr 15 13:09:19 2013 kevin andres
** Last update Wed May 22 15:20:30 2013 guillaume lefrant
*/

#include	"../../shell.h"

void            my_show_list(t_param *my_param)
{
  t_param       *move;
  int           i;

  i = 0;
  move = my_param;
  printf("-----\n");
  while (move)
    {
      printf("paramètre:\n");
      while (move->cmd != NULL && move->cmd[i] != '\0')
	{
	  printf("%s\n", move->cmd[i]);
	  i++;
	}
      printf("end: %d\n", move->end);
      printf("file_name: %s\n", move->file_name);
      printf("file_name2: %s\n", move->file_name2);
      printf("flag_pipe: %d\n", move->flag_pipe);
      printf("flag_redir: %d\n", move->flag_redir);
      printf("flag_redir2: %d\n", move->flag_redir2);
      printf("-----\n");
      i = 0;
      move = move->prev;
    }
}

void	my_show_struct(t_param *move)
{
  int	i;

  i = 0;
  printf("******\n");
  printf("parametre:\n");
  while (move->cmd != NULL && move->cmd[i] != '\0')
    {
      printf("%s\n", move->cmd[i]);
      i++;
    }
  printf("end: %d\n", move->end);
  printf("file_name: %s\n", move->file_name);
  printf("file_name2: %s\n", move->file_name2);
  printf("flag_pipe: %d\n", move->flag_pipe);
  printf("flag_redir: %d\n", move->flag_redir);
  printf("flag_redir2: %d\n", move->flag_redir2);
  printf("******\n");
}
