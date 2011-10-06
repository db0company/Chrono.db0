/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include		<stdlib.h>
#include		<unistd.h>

#include		"db0chrono.h"

extern t_db0chrono *	c_global;

void			update_signal(__attribute__((unused))int sighandler)
{
  print_char("\n");
  if (!update_logfile(c_global))
    exit(EXIT_FAILURE);
  exit(EXIT_SUCCESS);
}
