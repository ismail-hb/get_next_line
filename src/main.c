/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:25:37 by ismail            #+#    #+#             */
/*   Updated: 2024/04/23 03:15:17 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char *str)
{
	if (str)
		free(str);

}
void	free_2D(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	free(arr);
}

void	init_data(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
}

void	cleanup_and_exit(int status, t_data *d)
{
	if (d->win)
	{
		mlx_destroy_window(d->mlx, d->win);
		// free(d->win);
	}
	if(d->d_img.img)
	{
		mlx_destroy_image(d->mlx, d->d_img.img);
	}
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		// free(d->mlx);
	}
	free_2D((char **)d->points);
	exit(status);
}

int	on_win_destroy(t_data *d)
{
	cleanup_and_exit(0, d);
	return (0);
}

int	on_keydown(int keycode, t_data *d)
{
	if (keycode == 65307)
		cleanup_and_exit(0, d);
	return (0);
}

int	ft_count_line(char *file)
{
	char	*str;
	int		line_num;
	int		fd;

	line_num = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	while (str)
	{
		line_num++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (line_num);
}

int	ft_count_split(char **line_len)
{
	int	y;

	y = 0;
	while(line_len[y])
		y++;
	return(y);
}



void	print_2D(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

ssize_t	**parse(char *file)
{
	ssize_t	**points;
	int		fd;
	int		line_num;
	int		line_len;
	char	*str;
	char	**str2;
	int		y;
	int		x;
	int		first_line_len;

	str2 = NULL;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_num = ft_count_line(file);
	if (line_num <= 0)
		return(close(fd), NULL);
	points = ft_calloc(line_num + 1, sizeof(ssize_t*));
	str = get_next_line(fd);
	first_line_len = -1;
	while (str)
	{
		free_2D(str2);
		str2 = ft_split(str, ' ');
		line_len = ft_count_split(str2);
		if (first_line_len == -1)
			first_line_len = line_len;
		else if (first_line_len != line_len)
			return (free_2D((char **)points), free_2D(str2), free(str), close(fd), NULL);
		points[y] = malloc(sizeof(ssize_t) * (line_len + 1));
		x = 0;
		while (str2[x])
		{
			points[y][x] = atoi(str2[x]);
			x++;
		}
		points[y][x] = INT_MAX;
		free(str);
		str = get_next_line(fd);
		y++;
	}
	points[y] = NULL;
	close(fd);
	free_2D(str2);
	free(str);
	return (points);
}

int	main(int ac, char **av)
{
	t_data	d;

	init_data(&d);
	(void)av;
	if (ac != 2)
		return (write(2, "Usage: ./fdf <map>\n", 19), 1);

	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIN_W, WIN_H, "fdf");
	d.d_img.img = mlx_new_image(d.mlx, WIN_W, WIN_H);
	d.d_img.addr = mlx_get_data_addr(d.d_img.img, &d.d_img.bits_per_pixel,
			&d.d_img.line_length, &d.d_img.endian);

	mlx_hook(d.win, ON_KEYDOWN, 1 << 0, on_keydown, &d);
	mlx_hook(d.win, ON_DESTROY, 0, on_win_destroy, &d);

	d.points = parse(av[1]);
	if (!d.points)
	{
		write(2, "Invalid map\n", 12);
		cleanup_and_exit(1, &d);
	}

	for (size_t y = 0; d.points[y]; y++)
	{
		for (size_t x = 0; d.points[y][x] != INT_MAX; x++)
		{
			printf("%2zd ", d.points[y][x]);
		}
		printf("\n");
	}

	render(d.points, &d);

	mlx_loop(d.mlx);
	return (0);
}
