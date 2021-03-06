/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:35:52 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:35:55 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	make_data_map(int fd, t_map *map)
{
	char	*line;
	int		ret;
	int		c_l;

	c_l = 0;
	line = NULL;
	map->line = 0;
	map->len = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (map->len != ft_strlen(line))
		{
			if (map->len < ft_strlen(line))
				map->len = ft_strlen(line);
			c_l++;
		}
		map->line++;
		free(line);
	}
	if (map->line < 2 || map->len < 2 || c_l > 1)
		return (0);
	return (1);
}

int	check_map_cara_help(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
	{
		map->p.p_x = j;
		map->p.p_y = i;
		map->p.nb_p++;
	}
	else if (map->map[i][j] == 'E')
	{
		map->exit.e_x = j;
		map->exit.e_y = i;
		map->exit.nb_e++;
	}
	else if (map->map[i][j] == 'C')
		map->exit.n_c_t_g++;
	else
	{
		if (map->map[i][j] != '1' && map->map[i][j] != '0')
			return (0);
	}
	return (1);
}

int	check_map_cara(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->exit.nb_e = 0;
	map->p.nb_p = 0;
	map->p.n_c_g = 0;
	map->exit.n_c_t_g = 0;
	map->p.move = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((check_map_cara_help(map, i, j)) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (map->exit.nb_e != 1 || map->p.nb_p != 1 || map->exit.n_c_t_g == 0)
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] || map->map[map->line - 1][i])
	{
		if (map->map[0][i] != '1')
			return (0);
		if (map->map[map->line - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->line)
	{
		if (map->map[i][map->len - 1] != '1' || map->map[i][0] != '1')
			return (0);
		i++;
	}
	if ((check_map_cara(map)) == 0)
		return (0);
	return (1);
}

int	parser_map(char *str, t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	if (make_data_map(fd, map) == 0)
		return (0);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	if (fill_data_map(fd, map) == 0)
		return (0);
	close(fd);
	if ((check_map(map)) == 0)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
		ft_printf("Error\nMap Error\n");
		exit(1);
	}
	return (1);
}
