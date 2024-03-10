#include "get_next_line.h"
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

char *get_next_line(int fd)
{
	char	buf[1];
	//char	b[BUFFER_SIZE];
	char	*b;
	int		nb_read;
	int		count;

	if (fd == -1)
		return (0);
	b = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	count = 0;
	while (nb_read != -1 && count < BUFFER_SIZE)
	{
		nb_read = read(fd, buf, 1);
		if (nb_read == -1)
			return (NULL);
		b[count] = buf[0]; 
		if (b[count] == '\n' && count + 1 < BUFFER_SIZE)
		{
			b[count + 1] = '\0';
			break ;
		}
		count++;
	}
	return (b);
}

int main()
{
	int fd = open("cat.txt", O_RDONLY);
	char *s;

	s = get_next_line(fd);
	if (s[10] == '\n')
		printf("newline\n");
	if (s[10] == '\0')
		printf("terminating\n");
	printf("1: %s\n", s);
	//printf("1: %s\n", get_next_line(fd));
	printf("2: %s\n", get_next_line(fd));
	printf("3: %s\n", get_next_line(fd));
	//printf("4: %s\n", get_next_line(fd));
}