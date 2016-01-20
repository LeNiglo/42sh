/*
** red.h for red in /home/tabti_l//project/unix/42sh
**
** Made by levi tabti
** Login   <tabti_l@epitech.net>
**
** Started on  Thu Apr  4 11:17:50 2013 levi tabti
** Last update Tue May 21 18:29:05 2013 guillaume lefrant
*/

#ifndef RED_H
# define RED_H

# define NOTHING		0
# define RED_SIMPLE_RIGHT	1
# define RED_DOUBLE_RIGHT	2
# define RED_SIMPLE_LEFT	3
# define RED_DOUBLE_LEFT	4

/*
** red.c
*/

void		red_right(int flag, int pipe_pre[2], char *file_name);

#endif
