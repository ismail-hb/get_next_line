/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:06:30 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/10 18:16:28 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_strcpy2(char *src, char *dest, ssize_t i);
char	*ft_realoc(char *str, ssize_t j);
char	*get_next_line(int fd);
char	*ft_strcpy(char *src, char *dest, ssize_t i);
ssize_t	check_buff(char *buffer);
ssize_t	ft_read(int fd, char **buffer);
ssize_t	ft_strlen(char *str);

#endif
