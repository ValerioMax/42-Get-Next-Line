/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:03:16 by valerio           #+#    #+#             */
/*   Updated: 2024/03/13 17:10:22 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

static char	*get_line(int fd, char *line)
{
	char	*buf;
	static int			n;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(line, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0) //n == -1 ? <=0 ?
		{
			free(buf);
			free(line); //serve?
			return (NULL);
		}
		buf[n] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);	
}

static char *get_real_line(char *line)
{
	char	*real_line;
	int			i;
	int			len;

	if (!line)
		return (NULL);
	len = 0;
	while (line[len] != '\n' && line[len]) //&&line[len]?
		len++;
	if (line[len] == '\n') //serve ?
		len++; //+=2 ?
	real_line = (char *) malloc(sizeof(char) * (len + 1)); //len + 1?
	if (!real_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		real_line[i] = line[i];
		i++;
	}
	real_line[i] = '\0';
	return (real_line);	
}

static char *update_line(char *line)
{
	int	i;
	int j;
	int k;
	char *s;

	if (!line)
		return (NULL); //serve?
	i = 0;
	while (line[i] != '\n' && line[i]) //&& line[i]?
		i++;
	if (line[i] == '\n')
		i++; //tolgo il newline
	j = 0;
	k = i;
	while (line[k++])
		j++;
	s = malloc(sizeof(char) * (j + 1)); //j+1 ?
	if (!s)
		return (NULL);
	j = 0;
	while (line[i])
		s[j++] = line[i++];
	s[j] = '\0';
	return (s);
}

char *get_next_line(int fd)
{
	static char	*line;
	char	*real;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = get_line(fd, line);
	real = get_real_line(line);
	line = update_line(line);
	return (real);
}



int main()
{	
	int fd = open("test/1-brouette.txt", O_RDONLY);
	static char *s;
	
	s = get_next_line(fd);
	for (int i = 0; s; i++)
	{
		printf("riga %d: %s\n", i, s);
		s = get_next_line(fd);
	}		
	return 0;
}
