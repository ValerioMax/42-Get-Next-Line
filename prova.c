#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

char *get_line(int fd)
{
	char	*buf;
	char	*out;
	int 	n;
	int 	*i;

	buf = (char*) malloc(sizeof(char) * (4 + 1));
	if (!buf)
		return (NULL);
	out = (char*) malloc(sizeof(char) * 100);
	if (!out)
		return (NULL);
	*i = 0;
	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, 4);
		if (n == -1)
		{
			free(buf);
			return (NULL);
		}
		
		buf[n] = '\0';
		j = 0;
		while (buf[j] != '\0')
		{
			out[i] = buf[j];
			i++;
			j++;
		}
	}
	out[i] = '\0';
	free(buf);
	return out;
}

int main()
{
	int fd = open("cat.txt", O_RDONLY);
	static char *s;

	s = get_line(fd);
	printf("%s\n", s);

	return 0;
}