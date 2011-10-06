/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include	<stdio.h>
#include	<stdbool.h>

bool		print_error(bool to_ret, char * msg)
{
  fprintf(stderr, "%s\n", msg);
  return (to_ret);
}
