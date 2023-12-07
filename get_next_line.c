/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/07 05:22:52 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realoc(char *str, ssize_t j)
{
	char	*newstr;
	ssize_t	i;

	i = 0;
	newstr = malloc(sizeof(char) * (BUFFER_SIZE * j + 2));
	while (str && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	free(str);
	while (i < (BUFFER_SIZE * j + 2))
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
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (-1);
	return (i);
}

ssize_t	ft_read(int fd, char **buffer)
{
	ssize_t	j;
	ssize_t	readvalue;

	j = 1;
	*buffer = ft_realoc(*buffer, j);
	while (check_buff(*buffer) != -1)
	{
		*buffer = ft_realoc(*buffer, j);
		readvalue = read(fd, *buffer, BUFFER_SIZE);
		if (readvalue != BUFFER_SIZE)
			break ;
		j++;
	}
	if (readvalue != BUFFER_SIZE)
		return ((ssize_t) -1);
	return (ft_strlen(*buffer));
}

char	*get_next_line(int fd)
{
	static char	saved_buffer[BUFFER_SIZE];
	char		*buffer;
	char		*final;
	ssize_t		i;

	buffer = NULL;
	i = 0;
	while (saved_buffer[i] != '\0' && saved_buffer[i] != '\n')
		i++;
	if (saved_buffer[i] == '\n')
		return (final = malloc(sizeof(char) * BUFFER_SIZE),
			ft_strcpy(saved_buffer, final, ++i));
	if (saved_buffer[i] == '\0')
		i = ft_read(fd, &buffer);
	if (i == -1)
	{
		final = malloc(sizeof(char) * ft_strlen(buffer));
		ft_strcpy2(buffer, final, 0);
	}
	if (i != -1)
	{
		final = malloc(sizeof(char) * i);
		ft_strcpy2(buffer, saved_buffer, i);
		ft_strcpy(buffer, final, i);
	}
	return (final);
}

// int main()
// {
// 	char src[] = "je m'appelle isamail";
// 	char *dest;
// 	dest = calloc(45, sizeof(char));
// 	printf("%s\n", ft_strcpy(src, dest, 10));
// 	printf("%s", src);
// }
