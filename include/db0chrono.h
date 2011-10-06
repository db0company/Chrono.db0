/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#ifndef		DB0CHRONO_H_
# define	DB0CHRONO_H_

#  define	TOTAL_HOUR	12
#  define	TOTAL_TIME	convert_hour(TOTAL_HOUR)

#  define	LOGFILE		".db0chrono"

#  define	convert_hour(value)	(value*3600)
#  define	convert_minuts(value)	(value*60)
#  define	convert2_hour(value)	(value/3600)
#  define	convert2_minuts(value)	(value/60)

#  define	print_char(value)	write(STDOUT_FILENO, value, sizeof(char))	

#  define	ERR_READ		-1
#  define	ERR_WRITE		-1
#  define	ERR_OPEN		-1

#  define	ERRMSG_NOFILE		"No such file or directory\n"

#  include	<stdbool.h>

typedef union	u_time
{
  int		time;
  char		buf[sizeof(int)];
}		ut_time;

typedef struct	s_clock
{
  int		hour;
  int		minut;
  int		second;
}		t_clock;

typedef struct	s_db0chrono
{
  ut_time	time;
  char		*logfile;
}		t_db0chrono;

bool		db0chrono(void);

bool		init_db0chrono(t_db0chrono *);

bool		update_logfile(t_db0chrono *);
void		update_signal(int);

char		*strdupcat(char *, char *);

bool		print_error(bool, char *);
bool		print_perror(bool, char *);

#endif		/* !DB0CHRONO_H_ */
