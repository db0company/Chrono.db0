/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"db0chrono.h"

bool		print_perror(bool to_ret, char * msg)
{
  perror(msg);
  return (to_ret);
}
