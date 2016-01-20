/*
** my_put_nbr.c for my_put_nbr in /home/lefran_g//Projects/Printf
**
** Made by guillaume lefrant
** Login   <lefran_g@epitech.net>
**
** Started on  Thu Nov  8 15:03:27 2012 guillaume lefrant
** Last update Tue May 21 18:11:27 2013 guillaume lefrant
*/

#include	"../shell.h"

void	my_put_nbr(int nb)
{
  int	div;
  int	rest;

  rest = nb % 10;
  div = nb / 10;
  if (div > -10 && div < 0)
    my_putchar('-');
  if (nb >= 10 || nb <= -10)
    my_put_nbr(div);
  if (rest < 0)
    rest = -rest;
  my_putchar(rest + 48);
}
