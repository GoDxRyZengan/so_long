/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:36:00 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:36:02 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	window_size(t_data *data)
{
	int	i;

	i = 0;
	data->w_r = 64;
	data->w_w = (data->map.len * data->w_r);
	data->w_h = (data->map.line * data->w_r);
	if (data->w_w > 1600 || data->w_h > 960)
	{
		data->w_r = 32;
		data->w_w = (data->map.len * data->w_r);
		data->w_h = (data->map.line * data->w_r);
		if (data->w_w > 1600 || data->w_h > 960)
		{
			while (data->map.map[i])
				free(data->map.map[i++]);
			free(data->map.map);
			write(1, "Error\nMap Size Error\n", 21);
			exit(1);
		}
	}
}

char	*rev(char *str)
{
	int i;
	int	j;
	char	*buff;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	buff = malloc(sizeof(char) * (i + 1));
	if (!buff)
		return (NULL);
	i--;
	while (i > 0)
	{
		buff[j] = str[i];
		j++;
		i--;
	}
	buff[j] = '\0';
	return (buff);
}
//ERREUR
int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (0);
	str = rev(str);
	i = 0;
	if (str[i] == 'r')
	{
		if (str[i + 1] == 'e')
		{
			if (str[i + 2] == 'b')
			{
				if (str[i + 3] == '.')
				{
					if (str[i + 4] != '\0' || str[i + 4] != '/')
						return (1);
				}
			}
		}
	}
	return (0);
}

int	create_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	map->map = malloc(sizeof(char *) * (map->line + 1));
	if (!map->map)
		return (0);
	while (i < map->line)
	{
		map->map[i] = malloc(sizeof(char) * (map->len + 1));
		if (!map->map[i])
		{
			while (j <= i)
				free(map->map[j++]);
			free(map->map);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	fill_data_map(int fd, t_map *map)
{
	char	*line;
	int		res;
	int		i;
	int		j;

	line = NULL;
	i = 0;
	res = 1;
	if ((create_map(map)) == 0)
		return (0);
	while (res != 0)
	{
		res = get_next_line(fd, &line);
		j = 0;
		while (line[j])
		{
			map->map[i][j] = line[j];
			j++;
		}
		map->map[i][j] = '\0';
		i++;
		free(line);
	}
	map->map[i] = NULL;
	return (1);
}
