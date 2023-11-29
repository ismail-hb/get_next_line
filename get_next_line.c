/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/28 16:31:04 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved_buffer[BUFFER_SIZE];
	char 		*buffer;
	int			i;

	i = 0;
	while (saved_buffer[i] != '\0' && saved_buffer[i] != '\n')
		i++;
	if (saved_buffer[i] == '\n')
		return (strdup(saved_buffer, ++i));

}
