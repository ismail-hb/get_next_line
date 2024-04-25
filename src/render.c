/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:44:55 by ismail            #+#    #+#             */
/*   Updated: 2024/04/23 04:01:30 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v2	get_map_size(ssize_t **points)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (points[y])
		y++;
	while (points[0][x] != INT_MAX)
		x++;

	return((t_v2){x, y});
}

void	render(ssize_t **points, t_data *d)
{
	int	y;
	int	x;
	t_v2	map_size;

	y = -1;
	map_size = get_map_size(d->points);
	while (points[++y])
	{
		x = -1;
		while (points[y][++x] != INT_MAX)
		{
			if (points[y][x + 1] != INT_MAX)
				draw_line_3D(
					(t_v3){x, y, points[y][x]},
					(t_v3){x + 1, y, points[y][x + 1]},
					&d->d_img, map_size);
			if (points[y + 1] != NULL)
				draw_line_3D(
					(t_v3){x, y, points[y][x]},
					(t_v3){x, y + 1, points[y + 1][x]},
					&d->d_img, map_size);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->d_img.img, 0, 0);
}


void	draw_line_3D(t_v3 p1, t_v3 p2, t_img *d_img, t_v2 map_size)
{
	double	mult;

	mult = 500 / map_size.x;
	p1.x -= map_size.x / 2;
	p2.x -= map_size.x / 2;
	p1.y -= map_size.y / 2;
	p2.y -= map_size.y / 2;

	p1.x *= mult;
	p1.y *= mult;
	p1.z *= mult;
	p2.x *= mult;
	p2.y *= mult;
	p2.z *= mult;

	draw_line(
		(t_v2){
			WIN_W / 2 + p1.x - p1.y * 1.73,
			WIN_H / 2 + p1.y + p1.x * 0.82 - p1.z
		},
		(t_v2){
			WIN_W / 2 + p2.x - p2.y * 1.73, 
			WIN_H / 2 + p2.y + p2.x * 0.82 - p2.z
		},
		d_img);
}

int	lerp(int from, int to, double alpha)
{
	return (from + (to - from) * alpha);
}

t_v2	lerp_v2(t_v2 p1, t_v2 p2, double alpha)
{
	t_v2	v;

	v.x = lerp(p1.x, p2.x, alpha);
	v.y = lerp(p1.y, p2.y, alpha);
	return (v);
}

void	draw_line(t_v2 p1, t_v2 p2, t_img *d_img)
{
	double	dist;
	double	curr;
	t_v2	pixel;

	dist = get_dist(p1, p2);
	curr = 0;
	while (curr < dist)
	{
		pixel = lerp_v2(p1, p2, curr / dist);
		draw_pixel(pixel.x, pixel.y, d_img);
		curr++;
	}
}

double get_dist(t_v2 p1, t_v2 p2)
{
	return (sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}

void	draw_pixel(int x, int y, t_img *d_img)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
	dst = d_img->addr + (y * d_img->line_length)
			+ (x * d_img->bits_per_pixel / 8);
	*(unsigned int *)dst = 0xFFFFFF;
}
