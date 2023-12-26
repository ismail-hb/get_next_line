/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/26 20:39:18 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_calloc(size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	str = malloc(size + 1);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_realloc(char *str, ssize_t j)
{
	char	*newstr;
	ssize_t	i;
	ssize_t	n;

	i = 0;
	if (BUFFER_SIZE < 100000)
		n = BUFFER_SIZE * j;
	else if (BUFFER_SIZE >= 100000)
		n = (BUFFER_SIZE * j) / BUFFER_SIZE;
	newstr = ft_calloc(BUFFER_SIZE * j);
	if (!newstr)
		return (NULL);
	while (str && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	free(str);
	while (i < n)
	{
		newstr[i] = '\0';
		i++;
	}
	return (newstr);
}

ssize_t	check_buff(char *buffer)
{
	ssize_t	i;

	i = 0;
	if (!buffer || !buffer[i])
		return (i);
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		return (-1);
	return (i);
}

ssize_t	ft_read(int fd, char **buffer)
{
	ssize_t	j;
	ssize_t	readvalue;

	j = 1;
	readvalue = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*buffer = NULL;
	while (check_buff(*buffer) != -1)
	{
		if (readvalue != BUFFER_SIZE)
			break ;
		*buffer = ft_realloc(*buffer, j);
		if (!*buffer)
			return (0);
		readvalue = read(fd, *buffer + BUFFER_SIZE * (j - 1), BUFFER_SIZE);
		if (check_buff(*buffer) == 0)
			return (0);
		j++;
	}
	if (readvalue == -1)
		return (0);
	if (readvalue != BUFFER_SIZE && check_buff(*buffer) != -1)
		return ((ssize_t) -1);
	return (ft_strlen(*buffer));
}

char	*get_next_line(int fd)
{
	static char	saved_buffer[BUFFER_SIZE + 1] = "\0";
	char		*buffer;
	char		*final;
	ssize_t		i;

	buffer = NULL;
	final = NULL;
	if (check_buff(saved_buffer) == -1)
	{
		i = 0;
		while (saved_buffer[i] != '\n')
			i++;
		final = ft_calloc(i + 1);
		ft_strcpy_memmove(saved_buffer, final, i + 1);
		return (final);
	}
	i = ft_read(fd, &buffer);
	if (!i && !saved_buffer[0])
	{
		free (buffer);
		return (NULL);
	}
	final = return_line(saved_buffer, buffer, &final, i);
	free(buffer);
	return (final);
}
