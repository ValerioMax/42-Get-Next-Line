/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valerio <valerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:14:48 by valerio           #+#    #+#             */
/*   Updated: 2024/03/15 00:54:55 by valerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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

/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	
	s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}
*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	
	s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j= 0;
	while (s1[j])
		s[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
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