
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//#define BUFFER_SIZE 3
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int         get_next_line(int fd, char **line);
char	    *ft_strdup(char *src);
size_t		ft_strlen(const char *s);
char	    *ft_strcpy(char *dest, const char *src);
char        *ft_strnew(size_t i);
char	    *ft_strchr(const char *s, int c);
void	    ft_strclr(char *s);
char	    *ft_strjoin(char *s1, char *s2);

#endif
