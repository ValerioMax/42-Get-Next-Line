/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:42:36 by valerio           #+#    #+#             */
/*   Updated: 2024/03/16 15:36:37 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

static char	*get_line(int fd, char *line)
{
	char	*buf;
	int		n;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(line, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1) // <=0?
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

static char	*real_line(char	*line)
{
	char	*out;
	int		len;
	int		i;

	if (!line[0])
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len])
		len++;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		out[i] = line[i];
	if (line[i])
		out[i++] = '\n';
	out[i] = '\0';
	return (out);
}

static char	*update_line(char *line)
{
	char	*new;
	char	*temp;

	temp = line;
	while (*temp && *temp != '\n')
		temp++;
	if (!*temp)
	{
		free(line);
		return (NULL);
	}
	temp++;
	new = ft_strdup(temp);
	free(line);
	return (new);
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
	//fd = 0; //check per input da terminale
	
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











