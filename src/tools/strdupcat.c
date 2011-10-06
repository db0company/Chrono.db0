/*
** Made by	db0
** Contact	db0company@gmail.com
** Website	http://db0.fr/
*/

#include	<stdlib.h>
#include	<string.h>

char		*strdupcat(char *str1, char *str2)
{
  int		i;
  int		j;
  char		*new;

  if (!(new = malloc((strlen(str1) + strlen(str2) + 2)
		     * sizeof(*new))))
    return (NULL);
  i = 0;
  while (str1 && str1[i])
    {
      new[i] = str1[i];
      i++;
    }
  new[i++] = '/';
  j = 0;
  while (str2 && str2[j])
    {
      new[i] = str2[j];
      j++;
      i++;
    }
  new[i] = '\0';
  return (new);
}
