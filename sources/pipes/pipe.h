/*
** pipe.h for pipe in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 07:42:25 2013 levi tabti
** Last update Wed May 22 15:17:21 2013 guillaume lefrant
*/

#ifndef PIPE_H
# define PIPE_H

# include "../../shell.h"

# define FIRST_PIPE		0
# define BETWEEN_PIPE		1
# define END_PIPE		2

/*
** pipes.c
*/

typedef struct s_shell t_shell;

int			*pipes(t_param exe, t_shell *sh, ...);
void			end_pipe(t_param exe, int pipe_pre[2], t_shell *sh);
int			*between_pipe(t_param exe, int pipe_pre[2], t_shell *sh);
int			*first_pipe(t_param exe, t_shell *sh);

/*
** exe_all.c
*/

void			new_param(t_param **, t_param);
int			exe_all(t_param *, t_shell *);

/*
** my_pipe.c
*/

void			my_pipe(int pipefd[2]);

/*
** my_fork.c
*/

int		my_fork();

/*
** my_dup2.c
*/

void		my_dup2(int fd1, int fd2);

/*
** my_execve.c
*/

void		my_execve_fork(t_param exe, t_shell *sh);
void		my_execve(t_param exe, t_shell *sh);

#endif
