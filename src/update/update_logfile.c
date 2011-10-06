/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include	<unistd.h>
#include	<fcntl.h>

#include	"db0chrono.h"

bool		update_logfile(t_db0chrono * c)
{
  int		fd;

  if ((fd = open(c->logfile, O_CREAT|O_TRUNC|O_WRONLY, 0600)) == ERR_OPEN)
    return (print_perror(false, "open"));
  if (c->time.time >= TOTAL_TIME)
    c->time.time = 0;
  if (write(fd, c->time.buf, sizeof(int)) == ERR_WRITE)
    return (print_perror(false, "write"));
  close(fd);
  return (true);
}
