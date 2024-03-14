#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

#define BUFFER_SIZE 6

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s) //
		return (0); //serve?
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	
	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i])
		if (str[i++] == (unsigned char) c)
			return (str + i);
	if (str[i] == (unsigned char) c)
		return (str + i);
	return (NULL);
}

static int	get_line(int fd, char *line)
{
	char	*buf;
	int	n;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (1);
	n = 1;
	while (!ft_strchr(line, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		printf("%d\n", n);
		if (n == -1) // <=0?
		{
			free(buf);
			free(line); //?
			return (1);
		}
		buf[n] = '\0';
		line = append(line, buf);
	}
	printf("%s\n", line);
	free(buf);
	if (n == 0)
		return (1);
	return (0);
}

static char	*real_line(char	*line)
{
	char	*out;
	int	len;
	int	i;

	printf("AAAA\n");
	printf("%s\n", line);
	printf("AAAA\n");
	if (!line)
		return (NULL);
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

static char	*update_line(char *line, int var)
{
	char	*new;
	int		i;
	int 	len;
	int 	j;

	if (var)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i])
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
	return (new); //NULL ?
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*out;
	int			var;

	//line = NULL;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	var = get_line(fd, line);
	printf("%s\n", line);
	out = real_line(line);
	line = update_line(line, var);
	return (out);
}

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
	
	

	/*
	char *s1;
	char *s2;

	s1 = malloc(5);
	s1[0] = 'c';
	s1[1] = 'i';
	s1[2] = 'a';
	s1[3] = 'o';
	s1[4] = '\0';

	s2 = malloc(4);
	s2[0] = ' ';
	s2[1] = 'O';
	s2[2] = 'K';
	s2[3] = '\0';

	printf("%s, %s\n", s1, s2);
	s1 = append(s1, s2);
	printf("%s\n", s1);

	free(s1);
	free(s2);
	*/
	
	return 0;
}