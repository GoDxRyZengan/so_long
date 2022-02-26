/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:35:21 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:35:28 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	get_texture_x32(t_data *data)
{
	data->tex.f = mlx_xpm_file_to_image(data->m_p, "./t/floor_x32.xpm",
			&data->w_r, &data->w_r);
	data->tex.e_c = mlx_xpm_file_to_image(data->m_p, "./t/door_x32.xpm",
			&data->w_r, &data->w_r);
	data->tex.e_o = mlx_xpm_file_to_image(data->m_p, "./t/o_door_x32.xpm",
			&data->w_r, &data->w_r);
	data->tex.p = mlx_xpm_file_to_image(data->m_p, "./t/player_x32.xpm",
			&data->w_r, &data->w_r);
	data->tex.w = mlx_xpm_file_to_image(data->m_p, "./t/wall_x32.xpm",
			&data->w_r, &data->w_r);
	data->tex.c = mlx_xpm_file_to_image(data->m_p, "./t/coll_x32.xpm",
			&data->w_r, &data->w_r);
}

void	get_texture(t_data *data)
{
	if (data->w_r == 64)
	{
		data->tex.f = mlx_xpm_file_to_image(data->m_p, "./t/floor_x64.xpm",
				&data->w_r, &data->w_r);
		data->tex.e_c = mlx_xpm_file_to_image(data->m_p, "./t/door_x64.xpm",
				&data->w_r, &data->w_r);
		data->tex.e_o = mlx_xpm_file_to_image(data->m_p, "./t/o_door_x64.xpm",
				&data->w_r, &data->w_r);
		data->tex.p = mlx_xpm_file_to_image(data->m_p, "./t/player_x64.xpm",
				&data->w_r, &data->w_r);
		data->tex.w = mlx_xpm_file_to_image(data->m_p, "./t/wall_x64.xpm",
				&data->w_r, &data->w_r);
		data->tex.c = mlx_xpm_file_to_image(data->m_p, "./t/coll_x64.xpm",
				&data->w_r, &data->w_r);
	}
	if (data->w_r == 32)
		get_texture_x32(data);
}
