/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:55:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/27 22:21:05 by ishouche         ###   ########.fr       */
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
	if ()
}
