/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>

#include	"db0chrono.h"

extern t_db0chrono *	c_global;

static void	convert_time(int time, t_clock * clock)
{
  clock->hour = time/3600;
  time %= 3600;
  clock->minut = time/60;
  time %= 60;
  clock->second = time;
}

bool		db0chrono(void)
{
  t_db0chrono	c;
  int		time_left;
  t_clock	clock;

  c.time.time = 0;
  if (!init_db0chrono(&c))
    return (false);
  convert_time(c.time.time, &clock);
  printf("Elapsed Time : %2d hour%c %2d minute%c %2d second%c\n",
	 clock.hour, (clock.hour > 0 ? 's' : ' '),
	 clock.minut, (clock.minut > 0 ? 's' : ' '),
	 clock.second, (clock.second > 0 ? 's' : ' '));
  fflush(stdout);
  while (c.time.time < TOTAL_TIME)
    {
      time_left = TOTAL_TIME - c.time.time;
      convert_time(time_left, &clock);
      printf("\rTime left : %2d hour%c %2d minute%c %2d second%c     ",
	     clock.hour, (clock.hour > 0 ? 's' : ' '),
	     clock.minut, (clock.minut > 0 ? 's' : ' '),
	     clock.second, (clock.second > 0 ? 's' : ' '));
      fflush(stdout);
      sleep(1);
      ++(c.time.time);
    }
  print_char("\n");
  if (!update_logfile(&c))
    return (false);
  return (true);
}
