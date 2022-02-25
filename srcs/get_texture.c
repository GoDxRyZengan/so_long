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

void        get_texture(t_data *data)
{
    if (data->win_ratio == 64)
    {
        data->texture.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor_x64.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.exit_close = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/door_x64.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.exit_open = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/open_door_x64.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.player = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_x64.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_x64.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.coll = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/coll_x64.xpm", &data->win_ratio, &data->win_ratio);
    }
    if (data->win_ratio == 32)
    {
        data->texture.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor_x32.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.exit_close = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/door_x32.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.exit_open = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/open_door_x32.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.player = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_x32.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_x32.xpm", &data->win_ratio, &data->win_ratio);
        data->texture.coll = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/coll_x32.xpm", &data->win_ratio, &data->win_ratio);
    }
}
