#include "get_next_line.h"
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

/*
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
*/



static char	*append(char *s1, char *s2)
{
	char	*s;
	size_t		i;
	size_t		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (s1); //oppure NULL?
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	j = 0;
	i = 0;
	while (s1[i])
	{
		s[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	free(s1);
	return (s);
}

static char	*get_line(int fd, char *line)
{
	char	*buf;
	int	n;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(line, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		//printf("%d\n", n);
		if (n == -1) // <=0?
		{
			free(buf);
			free(line); //?
			return (NULL);
		}
		buf[n] = '\0';
		line = append(line, buf);
		//printf("line: %s\n", line);
	}
	free(buf);
	//printf("OK\n");
	return (line);
}

static char	*real_line(char	*line)
{
	char	*out;
	int	len;
	int	i;
	
	//if (!line)
	//	return (NULL);
	if (!line[0])
	{
		//free(line);
		return (NULL);
	}
		
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len])
		len++;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		out[i] = line[i];
		i++;
	}
	if (line[i])
	{
		out[i] = '\n';
		out[i + 1] = '\0';
		return (out);
	}
	out[i] = '\0';
	return (out);
}

static char	*update_line(char *line)
{
	char	*new;
	int		i;
	int 	len;
	int 	j;

	//if (!line)
	//	return (NULL);

	//printf("update1: %s\n", new);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	//printf("char: %c\n", line[i]);
	if (line[i] == '\0')
	{
		free(line);
		//printf("NULL\n");
		return (NULL);
	}
	if (line[i] != '\0')
	{
		i++;
		j = i;
		len = 0;
		while (line[i])
		{
			len++;
			i++;
		}
		new = malloc(sizeof(char) * (len + 1));
		if (!new)
			return (NULL);
		i = 0;
		while (line[j])
		{
			new[i] = line[j];
			i++;
			j++;
		}
		new[i] = '\0';
	}
	free(line);
	//printf("update: %s\n", new);
	return (new); //NULL ?
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*out;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = get_line(fd, line);
	out = real_line(line);
	line = update_line(line);
	return (out);
}

/*
int main()
{
	
	int fd = open("cat.txt", O_RDONLY);
	static char *s;

	s = get_next_line(fd);
	for (int i = 1; s; i++)
	{
		printf("riga %d: %s\n", i, s);
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	
	return 0;
}






*/
