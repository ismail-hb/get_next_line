/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/15 22:01:30 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(char *str, size_t size)
{
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * size + 1);
	while (i <= (size + 1))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_realoc(char *str, ssize_t j)
{
	char	*newstr;
	ssize_t	i;

	i = 0;
	newstr = malloc(sizeof(char) * (BUFFER_SIZE * j + 1));
	if (!newstr)
		return (NULL);
	while (str && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	// printf("%s\n", newstr);
	free(str);
	while (i < (BUFFER_SIZE * j + 1))
	{
		newstr[i] = '\0';
		i++;
	}
	// printf("%s\n", newstr);
	return (newstr);
}

ssize_t	check_buff(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (-1);
	return (i);
}

ssize_t	ft_read(int fd, char **buffer)
{
	ssize_t	j;
	ssize_t	readvalue = BUFFER_SIZE;

	j = 1;
	*buffer = ft_realoc(*buffer, j);
	if (!*buffer)
		return (0);
	readvalue = read(fd, *buffer, BUFFER_SIZE);
	while (check_buff(*buffer) != -1)
	{
		if (readvalue != BUFFER_SIZE)
			break ;
		*buffer = ft_realoc(*buffer, j);
		if (!*buffer)
			return(0);
		readvalue = read(fd, *buffer + (BUFFER_SIZE * j), BUFFER_SIZE);
		j++;
	}
	if (readvalue != BUFFER_SIZE)
		return ((ssize_t) -1);
	return (ft_strlen(*buffer));
}

char	*get_next_line(int fd)
{
	static char	saved_buffer[BUFFER_SIZE + 1];
	char		*buffer;
	char		*final;
	ssize_t		i;

	buffer = NULL;
	final = NULL;
	// i = 0;
	// while (saved_buffer[i] != '\0' && saved_buffer[i] != '\n')
	// 	i++;
	// if (saved_buffer[i] == '\n')
	// 	return (final = malloc(sizeof(char) * BUFFER_SIZE),
	// 		ft_strcpy(saved_buffer, final, ++i));
	// if (saved_buffer[i] != '\n')
		i = ft_read(fd, &buffer);
	if (!i)
		return (NULL);
	if (i == -1)
	{
		final = ft_calloc(final, ft_strlen(buffer));
		ft_strcpy2(buffer, final, 0);
	}
	if (i != -1)
	{
		final = ft_calloc(final, i);
		ft_strcpy2(buffer, saved_buffer, i);
		ft_strcpy(buffer, final, i);
	}
	free(buffer);
	return (final);
}
