/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:03:16 by valerio           #+#    #+#             */
/*   Updated: 2024/03/10 21:03:25 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>	//provv
#include <stdio.h>	//provv

char *get_next_line(int fd)
{
	char	buf[1];
	char	*b;
	int		nb_read;
	int		i;

	if (fd == -1)
		return (NULL);
	b = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (!b);
		return (NULL);
	i = 0;
	while (nb_read != -1 && i < BUFFER_SIZE)
	{
		nb_read = read(fd, buf, 1);
		if (nb_read == -1)
			return (NULL);
		b[i] = buf[0]; 
		if (b[i] == '\n' && i + 1 < BUFFER_SIZE)
		{
			b[i + 1] = '\0';
			break ;
		}
		i++;
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
