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