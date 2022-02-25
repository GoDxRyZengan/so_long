/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:34:37 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 15:06:59 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	do_pce(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.exit_close, (j * (data->win_ratio)), (i * (data->win_ratio)));
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.coll, (j * (data->win_ratio)), (i * (data->win_ratio)));
			if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.player, (j * (data->win_ratio)), (i * (data->win_ratio)));
			j++;
		}
		i++;
	}
}

void	do_floor(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, (j * (data->win_ratio)), (i * (data->win_ratio)));
			j++;
		}
		i++;
	}
}

void	do_wall(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.wall, (j * (data->win_ratio)), (i * (data->win_ratio)));
			j++;
		}
		i++;
	}
}

int	free_game(t_data *data)
{
	int		i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
	mlx_destroy_image(data->mlx_ptr, data->texture.wall);
	mlx_destroy_image(data->mlx_ptr, data->texture.exit_close);
	mlx_destroy_image(data->mlx_ptr, data->texture.exit_open);
	mlx_destroy_image(data->mlx_ptr, data->texture.floor);
	mlx_destroy_image(data->mlx_ptr, data->texture.player);
	mlx_destroy_image(data->mlx_ptr, data->texture.coll);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
	return (0);
}

void	do_map(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		printf("Error\nMlx Error\n");
		return ;
	}
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "so_long")) == NULL)
	{
		free(data->win_ptr);
		free(data->mlx_ptr);
		printf("Error\nMlx Error\n");
		return ;
	}
	get_texture(data);
	do_wall(data);
	do_floor(data);
	do_pce(data);
	mlx_key_hook(data->win_ptr, keyboard_action, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, free_game, data);
	mlx_loop(data->mlx_ptr);
	free(data->mlx_ptr);
}
