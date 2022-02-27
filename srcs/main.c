/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:35:44 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:35:48 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || (check_name(argv[1])) == 0)
	{
		write(1, "Error\nWrong Argument\n", 21);
		return (0);
	}
	if ((parser_map(argv[1], &data.map)) == 0)
	{
		write(1, "Error\nMap Error\n", 16);
		return (0);
	}
	window_size(&data);
	do_map(&data);
	return (0);
}
