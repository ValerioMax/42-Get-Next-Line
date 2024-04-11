/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdessena <vdessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:15:32 by vdessena          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:31 by vdessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (s1);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	j = 0;
	i = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest || (!dest && !src) || n == 0)
		return (dest);
	while (n--)
		((char *) dest)[n] = ((char *) src)[n];
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*pt;
	size_t	len;

	len = ft_strlen(s);
	pt = (char *) malloc((len + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	pt = ft_memcpy(pt, s, len + 1);
	return (pt);
}
