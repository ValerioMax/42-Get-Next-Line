/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdessena <vdessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:03:16 by valerio           #+#    #+#             */
/*   Updated: 2024/03/11 19:23:51 by vdessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

char *get_next_line(int fd)
{
	char	*buf;
	static char	*b;
	int		nb_read;
	int		i;

	if (fd == -1)
		return (NULL);
	b = (char *) malloc(sizeof(char) * (BUFFER_SIZE));
	if (!b)
		return (NULL);
	buf = (char *) malloc(sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		nb_read = read(fd, buf, 1);
		if (nb_read <= 0)
		{
			free(buf);
			free(b);
			return (NULL);
		}
		//	return (NULL);
		b[i] = buf[0];
		if (b[i] == '\n' && i  < BUFFER_SIZE) //i + 1?
		{
			b[i + 1] = '\0';
			break ;
		}
		i++;
	}
	free(buf);
	return (b);
}





int main()
{
	int fd = open("test/1-brouette.txt", O_RDONLY);
	char *s = get_next_line(fd);
	for (int i = 1; s != NULL; i++)
	{
		printf("%d: %s\n", i, s);
		free(s);
		s = get_next_line(fd);
	}
	return 0;
}

