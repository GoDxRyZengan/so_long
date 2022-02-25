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

int     main(int argc, char **argv)
{
    t_data  data; 
    if (argc !=2 || (check_name(argv[1])) == 0)
    {
        printf("Error\nWrong Argument\n");
        return (0);
    }
    if ((parser_map(argv[1], &data.map)) == 0)
    {
        printf("Error\nMap Error\n");
        return (0);
    }
    if ((window_size(&data)) == 0)
    {
        printf("Error\nMap Size Error\n");
        return (0);
    }
    do_map(&data);
    return (0);
}
