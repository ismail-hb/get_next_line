/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:44:55 by ismail            #+#    #+#             */
/*   Updated: 2024/04/23 03:44:56 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_v2 p1, t_v2 p2, t_img *d_img);
double	get_dist(t_v2 p1, t_v2 p2);
void	draw_pixel(int x, int y, t_img *d_img);

void	render(ssize_t **points, t_data *d)
{
	(void)points;
	draw_line((t_v2){0, }, (t_v2){200, 200}, &d->d_img);
	mlx_put_image_to_window(d->mlx, d->win, d->d_img.img, 0, 0);
}


/*

4
3     X
2   O
1 X
0 1 2 3 4

X1 = (1,1)
X2 = (3,3)

(1,1) + ((3,3) - (1,1)) * 0.5

*/

/*

 X  U  U  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 U  U  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
 0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
 0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
 0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
 0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
 0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
 0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

*/

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

/**
 * dist = V( (x2 - x1)^2 + (y2 - y1)^2 )
*/
double get_dist(t_v2 p1, t_v2 p2)
{
	return (sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}

void	draw_pixel(int x, int y, t_img *d_img)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 1000 || x > 500)
		return ;
	dst = d_img->addr + (y * d_img->line_length)
			+ (x * d_img->bits_per_pixel / 8);
	*(unsigned int *)dst = 0xFFFFFF;
}
