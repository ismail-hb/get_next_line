/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:06:30 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/28 20:58:52 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*return_line(char *saved_buffer, char *buffer, char **final, ssize_t i);
void	ft_strcpy(char *src, char *dest, ssize_t i);
void	ft_bzero(char *str, ssize_t size);
char	*ft_realoc(char *str, ssize_t j);
char	*ft_calloc(size_t size);
char	*get_next_line(int fd);
char	*ft_strcpy_memmove(char *src, char *dest, ssize_t i);
ssize_t	check_buff(char *buffer);
ssize_t	ft_read(int fd, char **buffer, char *saved_buffer);
ssize_t	ft_strlen(char *str);

#endif
