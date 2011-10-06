/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<fcntl.h>

#include	"db0chrono.h"

t_db0chrono *	c_global;

static bool    	get_logfile(char ** logfile)
{
  char *	home;

  if (!(home = getenv("HOME")))
    return (print_perror(false, "getenv"));
  if (!(*logfile = strdupcat(home, LOGFILE)))
    return (print_perror(false, "malloc"));
  return (true);
}

bool		init_db0chrono(t_db0chrono * c)
{
  int		fd;
  int		r;

  c_global = c;
  if (!get_logfile(&(c->logfile)))
    return (false);
  if (!access(c->logfile, F_OK))
    {
      if ((fd = open(c->logfile, O_RDONLY)) == ERR_OPEN)
	return (print_perror(false, "open"));
      if ((r = read(fd, c->time.buf, sizeof(int))) == ERR_READ)
	return (print_perror(false, "read"));
      close(fd);
    }
  if ((signal(SIGINT, update_signal) == SIG_ERR)
      || (signal(SIGQUIT, update_signal) == SIG_ERR))
    return (print_perror(false, "signal"));
  return (true);
}
