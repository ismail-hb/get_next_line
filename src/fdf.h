/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:25:42 by ismail            #+#    #+#             */
/*   Updated: 2024/04/23 03:53:40 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // TODO TEMP

# define ON_KEYDOWN	2
# define ON_DESTROY	17

# define WIN_W 1920
# define WIN_H 1080

typedef struct s_v2
{
	int	x;
	int	y;
}	t_v2;

typedef struct s_v3
{
	int	x;
	int	y;
	int	z;
}	t_v3;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	d_img;
	ssize_t	**points;
}	t_data;

void	render(ssize_t **points, t_data *d);

#endif
