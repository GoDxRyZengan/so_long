/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:35:36 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:35:39 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	keyboard_d(t_data *data)
{
	if (data->map.map[data->map.p.p_y][data->map.p.p_x + 1] != '1')
	{
		if ((data->map.map[data->map.p.p_y][data->map.p.p_x + 1] == 'E')
				&& (data->map.p.n_c_g != data->map.exit.n_c_t_g))
			return (0);
		else if ((data->map.map[data->map.p.p_y][data->map.p.p_x + 1] == 'E')
				&& (data->map.p.n_c_g == data->map.exit.n_c_t_g))
			return (free_game(data));
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.f,
			((data->map.p.p_x) * (data->w_r)),
			((data->map.p.p_y) * (data->w_r)));
		if (data->map.map[data->map.p.p_y][data->map.p.p_x + 1] == 'C')
			data->map.p.n_c_g++;
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.p,
			((data->map.p.p_x + 1) * (data->w_r)),
			((data->map.p.p_y) * (data->w_r)));
		data->map.map[data->map.p.p_y][data->map.p.p_x] = '0';
		data->map.map[data->map.p.p_y][data->map.p.p_x + 1] = 'P';
		data->map.p.p_x = data->map.p.p_x + 1;
		data->map.p.move = data->map.p.move + 1;
		printf("Move : %d\n", data->map.p.move);
	}
	return (0);
}

int	keyboard_a(t_data *data)
{
	if (data->map.map[data->map.p.p_y][data->map.p.p_x - 1] != '1')
	{
		if ((data->map.map[data->map.p.p_y][data->map.p.p_x - 1] == 'E')
				&& (data->map.p.n_c_g != data->map.exit.n_c_t_g))
			return (0);
		else if ((data->map.map[data->map.p.p_y][data->map.p.p_x - 1] == 'E')
				&& (data->map.p.n_c_g == data->map.exit.n_c_t_g))
			return (free_game(data));
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.f,
			((data->map.p.p_x) * (data->w_r)),
			((data->map.p.p_y) * (data->w_r)));
		if (data->map.map[data->map.p.p_y][data->map.p.p_x - 1] == 'C')
			data->map.p.n_c_g++;
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.p,
			((data->map.p.p_x - 1) * (data->w_r)),
			((data->map.p.p_y) * (data->w_r)));
		data->map.map[data->map.p.p_y][data->map.p.p_x] = '0';
		data->map.map[data->map.p.p_y][data->map.p.p_x - 1] = 'P';
		data->map.p.p_x = data->map.p.p_x - 1;
		data->map.p.move = data->map.p.move + 1;
		printf("Move : %d\n", data->map.p.move);
	}
	return (0);
}

int	keyboard_w(t_data *data)
{
	if (data->map.map[data->map.p.p_y - 1][data->map.p.p_x] != '1')
	{
		if ((data->map.map[data->map.p.p_y - 1][data->map.p.p_x] == 'E')
				&& (data->map.p.n_c_g != data->map.exit.n_c_t_g))
			return (0);
		else if ((data->map.map[data->map.p.p_y - 1][data->map.p.p_x] == 'E')
				&& (data->map.p.n_c_g == data->map.exit.n_c_t_g))
			return (free_game(data));
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.f,
			((data->map.p.p_x) * (data->w_r)),
			((data->map.p.p_y) * (data->w_r)));
		if (data->map.map[data->map.p.p_y - 1][data->map.p.p_x] == 'C')
			data->map.p.n_c_g++;
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.p,
			((data->map.p.p_x) * (data->w_r)),
			((data->map.p.p_y - 1) * (data->w_r)));
		data->map.map[data->map.p.p_y][data->map.p.p_x] = '0';
		data->map.map[data->map.p.p_y - 1][data->map.p.p_x] = 'P';
		data->map.p.p_y = data->map.p.p_y - 1;
		data->map.p.move = data->map.p.move + 1;
		printf("Move : %d\n", data->map.p.move);
	}
	return (0);
}

int	keyboard_s(t_data *data)
{
	if (data->map.map[data->map.p.p_y + 1][data->map.p.p_x] != '1')
	{
		if ((data->map.map[data->map.p.p_y + 1][data->map.p.p_x] == 'E')
				&& (data->map.p.n_c_g != data->map.exit.n_c_t_g))
			return (0);
		else if ((data->map.map[data->map.p.p_y + 1][data->map.p.p_x] == 'E')
				&& (data->map.p.n_c_g == data->map.exit.n_c_t_g))
			return (free_game(data));
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.f,
			((data->map.p.p_x) * (data->w_r)),
			((data->map.p.p_y) * (data->w_r)));
		if (data->map.map[data->map.p.p_y + 1][data->map.p.p_x] == 'C')
			data->map.p.n_c_g++;
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.p,
			((data->map.p.p_x) * (data->w_r)),
			((data->map.p.p_y + 1) * (data->w_r)));
		data->map.map[data->map.p.p_y][data->map.p.p_x] = '0';
		data->map.map[data->map.p.p_y][data->map.p.p_x] = 'P';
		data->map.p.p_y = data->map.p.p_y + 1;
		data->map.p.move = data->map.p.move + 1;
		printf("Move : %d\n", data->map.p.move);
	}
	return (0);
}

int	keyboard_gestion(int touch, t_data *data)
{
	if (touch == 65307)
		return (free_game(data));
	if (touch == 100)
		keyboard_d(data);
	if (touch == 97)
		keyboard_a(data);
	if (touch == 119)
		keyboard_w(data);
	if (touch == 115)
		keyboard_s(data);
	if (data->map.p.n_c_g == data->map.exit.n_c_t_g)
		mlx_put_image_to_window(data->m_p, data->w_p, data->tex.e_o,
			((data->map.exit.e_x) * (data->w_r)),
			((data->map.exit.e_y) * (data->w_r)));
	return (0);
}
