/*
** my_putchar.c for my_putchar in /home/lefran_g//Projects/Printf
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Thu Nov  8 15:01:15 2012 guillaume lefrant
** Last update Tue May 21 18:11:48 2013 guillaume lefrant
*/

#include "../shell.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
