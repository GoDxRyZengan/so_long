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
				mlx_put_image_to_window(data->m_p, data->w_p,
					data->tex.e_c, (j * (data->w_r)),
					(i * (data->w_r)));
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->m_p, data->w_p,
					data->tex.c, (j * (data->w_r)),
					(i * (data->w_r)));
			if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->m_p, data->w_p,
					data->tex.p, (j * (data->w_r)),
					(i * (data->w_r)));
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
				mlx_put_image_to_window(data->m_p, data->w_p,
					data->tex.f, (j * (data->w_r)),
					(i * (data->w_r)));
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
				mlx_put_image_to_window(data->m_p, data->w_p,
					data->tex.w, (j * (data->w_r)),
					(i * (data->w_r)));
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
	mlx_destroy_image(data->m_p, data->tex.w);
	mlx_destroy_image(data->m_p, data->tex.e_c);
	mlx_destroy_image(data->m_p, data->tex.e_o);
	mlx_destroy_image(data->m_p, data->tex.f);
	mlx_destroy_image(data->m_p, data->tex.p);
	mlx_destroy_image(data->m_p, data->tex.c);
	mlx_destroy_window(data->m_p, data->w_p);
	mlx_destroy_display(data->m_p);
	free(data->m_p);
	exit(1);
	return (0);
}

void	do_map(t_data *data)
{
	data->m_p = mlx_init();
	if (data->m_p == NULL)
	{
		printf("Error\nMlx Error\n");
		return ;
	}
	data->w_p = mlx_new_window(data->m_p, data->w_w, data->w_h, "so_long");
	if (data->w_p == NULL)
	{
		free(data->w_p);
		free(data->m_p);
		printf("Error\nMlx Error\n");
		return ;
	}
	get_texture(data);
	do_wall(data);
	do_floor(data);
	do_pce(data);
	mlx_key_hook(data->w_p, keyboard_gestion, data);
	mlx_hook(data->w_p, 17, 1L << 17, free_game, data);
	mlx_loop(data->m_p);
}
