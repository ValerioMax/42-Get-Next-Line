#include "get_next_line.h"
#include <fcntl.h>

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	buf[100];	// stores the characters read
	char	b[100];
	int	fd;		// file descriptor to read
	int	nb_read;	// stores read's return value
	int	count;		// counts the number of reads

//	Open the cat.txt file in read only mode
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
//	Initialize the count variables
	nb_read = -1;
	count = 0;
	while (1)
	{
		nb_read = read(fd, buf, 1);
		if (nb_read == -1)
		{
			printf("Read error!\n");
			return (1);
		}
		b[count] = buf[0]; 
		if (b[count] == '\n')
		{
			b[count] = '\0';
			printf("%s\n", b);
			break ;
		}
		//buf[nb_read] = '\0';
		//printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, buf);
		count++;
	}
//	Close the opened file descriptor
	close(fd);
	return (0);
}