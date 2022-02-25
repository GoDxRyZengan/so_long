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

int     window_size(t_data *data)
{
    data->win_ratio = 64;
    data->win_width = (data->map.len * data->win_ratio);
    data->win_height = (data->map.line * data->win_ratio);
    if (data->win_width > 1600 || data->win_height > 960)
    {
        data->win_ratio = 32;
        data->win_width = (data->map.len * data->win_ratio);
        data->win_height = (data->map.line * data->win_ratio);
        if (data->win_width > 1600 || data->win_height > 960)
            return (0);
    }
    return (1);
}

int     check_name(char* str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    printf("%d\n", i);
    i = i - 4;
    printf("%d\n", i);
    printf("%c\n", str[i]);
    if (str[i] == '.')
    {
        if (str[i + 1] == 'b')
        {
            if (str[i + 2] == 'e')
            {
                if (str[i + 3] == 'r')
                    return (1);
            }
        }
    }
    return (0);
}
