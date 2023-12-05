/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/05 12:30:45 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *src, char *dest, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	j = 0;
	while (src[i] != '\0')
	{
		src[j] = src[i];
		j++;
		i++;
	}
	src[j] = '\0';
	return(dest);
}

char	*ft_realoc(char *str, ssize_t j)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = malloc(sizeof(char) * (BUFFER_SIZE * j));
	while(str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	free(str);
	newstr[i] = '\0';
	return(newstr);
}

char	*ft_read(int fd, char **buffer, char *saved_buffer)
{
	ssize_t	j;
	size_t	readvalue;
	j = 1;
	while (check_buff(buffer) == 0)
	{
		*buffer = ft_realoc(buffer, j);
		readvalue = read(fd, buffer, BUFFER_SIZE);

	}

}

char	*get_next_line(int fd)
{
	static char	saved_buffer[BUFFER_SIZE];
	char 		*buffer;
	char		*final;
	ssize_t		i;

	i = 0;
	while (saved_buffer[i] != '\0' && saved_buffer[i] != '\n')
		i++;
	if (saved_buffer[i] == '\n')
		return (ft_strcpy(saved_buffer, final, ++i));
	if (saved_buffer[i] == '\0')
		final = ft_read(fd, buffer, saved_buffer);
}

// int main()
// {
// 	char src[] = "je m'appelle isamail";
// 	char *dest;
// 	dest = calloc(45, sizeof(char));
// 	printf("%s\n", ft_strcpy(src, dest, 10));
// 	printf("%s", src);
// }
