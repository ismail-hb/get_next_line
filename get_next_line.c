/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/28 22:41:45 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_calloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(size + 1);
	if (!str)
		return (NULL);
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

	i = 0;
	newstr = ft_calloc(BUFFER_SIZE * j);
	if (!newstr)
		return (free(str), NULL);
	while (str && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	free(str);
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

ssize_t	ft_read(int fd, char **buffer, char *saved_buffer)
{
	ssize_t	j;
	ssize_t	readvalue;

	j = 1;
	readvalue = BUFFER_SIZE;
	*buffer = NULL;
	while (check_buff(*buffer) != -1)
	{
		if (readvalue != BUFFER_SIZE)
			break ;
		*buffer = ft_realloc(*buffer, j);
		if (!*buffer)
			return (0);
		readvalue = read(fd, *buffer + BUFFER_SIZE * (j - 1), BUFFER_SIZE);
		if (readvalue == -1)
			return (ft_bzero(saved_buffer, BUFFER_SIZE + 1), 0);
		if (check_buff(*buffer) == 0)
			return (0);
		j++;
	}
	if (readvalue != BUFFER_SIZE && check_buff(*buffer) != -1)
		return ((ssize_t) - 1);
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_buff(saved_buffer) == -1)
	{
		i = 0;
		while (saved_buffer[i] != '\n')
			i++;
		final = ft_calloc(i + 1);
		if (final)
			ft_strcpy_memmove(saved_buffer, final, i + 1);
		return (final);
	}
	i = ft_read(fd, &buffer, saved_buffer);
	if (!i && !saved_buffer[0])
		return (free(buffer), NULL);
	final = return_line(saved_buffer, buffer, &final, i);
	free(buffer);
	return (final);
}
