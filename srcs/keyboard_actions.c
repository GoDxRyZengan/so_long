#include "../include/so_long.h"

int     keyboard_action(int touch, t_data *data)
{
    if (touch == 65307)
        return (free_game(data));
    if (touch == 100)
    {
        if (data->map.map[data->map.player.p_y][data->map.player.p_x + 1] != '1')
        {
            if ((data->map.map[data->map.player.p_y][data->map.player.p_x + 1] == 'E') && (data->map.player.nb_coll_get != data->map.exit.nb_coll_to_get))
                return (0);
            else if ((data->map.map[data->map.player.p_y][data->map.player.p_x + 1] == 'E') && (data->map.player.nb_coll_get == data->map.exit.nb_coll_to_get))
                return (free_game(data));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            if (data->map.map[data->map.player.p_y][data->map.player.p_x + 1] == 'C')
                data->map.player.nb_coll_get++;
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.player, ((data->map.player.p_x + 1) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            data->map.map[data->map.player.p_y][data->map.player.p_x] = '0';
            data->map.map[data->map.player.p_y][data->map.player.p_x + 1] = 'P';
            data->map.player.p_x = data->map.player.p_x + 1;
            data->map.player.move = data->map.player.move + 1;
        }
    }
    if (touch == 97)
    {
        if (data->map.map[data->map.player.p_y][data->map.player.p_x - 1] != '1')
        {
            if ((data->map.map[data->map.player.p_y][data->map.player.p_x - 1] == 'E') && (data->map.player.nb_coll_get != data->map.exit.nb_coll_to_get))
                return (0);
            else if ((data->map.map[data->map.player.p_y][data->map.player.p_x - 1] == 'E') && (data->map.player.nb_coll_get == data->map.exit.nb_coll_to_get))
                return (free_game(data));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            if (data->map.map[data->map.player.p_y][data->map.player.p_x - 1] == 'C')
                data->map.player.nb_coll_get++;
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.player, ((data->map.player.p_x - 1) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            data->map.map[data->map.player.p_y][data->map.player.p_x] = '0';
            data->map.map[data->map.player.p_y][data->map.player.p_x - 1] = 'P';
            data->map.player.p_x = data->map.player.p_x - 1;
            data->map.player.move = data->map.player.move + 1;
        }
    }
    if (touch == 119)
    {
        if (data->map.map[data->map.player.p_y - 1][data->map.player.p_x] != '1')
        {
            if ((data->map.map[data->map.player.p_y - 1][data->map.player.p_x] == 'E') && (data->map.player.nb_coll_get != data->map.exit.nb_coll_to_get))
                return (0);
            else if ((data->map.map[data->map.player.p_y - 1][data->map.player.p_x] == 'E') && (data->map.player.nb_coll_get == data->map.exit.nb_coll_to_get))
                return (free_game(data));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            if (data->map.map[data->map.player.p_y - 1][data->map.player.p_x] == 'C')
                data->map.player.nb_coll_get++;
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.player, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y - 1) * (data->win_ratio)));
            data->map.map[data->map.player.p_y][data->map.player.p_x] = '0';
            data->map.map[data->map.player.p_y - 1][data->map.player.p_x] = 'P';
            data->map.player.p_y = data->map.player.p_y - 1;
            data->map.player.move = data->map.player.move + 1;
        }
    }
    if (touch == 115)
    {
        if (data->map.map[data->map.player.p_y + 1][data->map.player.p_x] != '1')
        {
            if ((data->map.map[data->map.player.p_y + 1][data->map.player.p_x] == 'E') && (data->map.player.nb_coll_get != data->map.exit.nb_coll_to_get))
                return (0);
            else if ((data->map.map[data->map.player.p_y + 1][data->map.player.p_x] == 'E') && (data->map.player.nb_coll_get == data->map.exit.nb_coll_to_get))
                return (free_game(data));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            if (data->map.map[data->map.player.p_y + 1][data->map.player.p_x] == 'C')
                data->map.player.nb_coll_get++;
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.floor, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y) * (data->win_ratio)));
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.player, ((data->map.player.p_x) * (data->win_ratio)), ((data->map.player.p_y + 1) * (data->win_ratio)));
            data->map.map[data->map.player.p_y][data->map.player.p_x] = '0';
            data->map.map[data->map.player.p_y][data->map.player.p_x] = 'P';
            data->map.player.p_y = data->map.player.p_y + 1;
            data->map.player.move = data->map.player.move + 1;
        }
    }
    if (data->map.player.nb_coll_get == data->map.exit.nb_coll_to_get)
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture.exit_open, ((data->map.exit.e_x) * (data->win_ratio)), ((data->map.exit.e_y) * (data->win_ratio)));
    printf("Move : %d\n", data->map.player.move);
    return(0);
}