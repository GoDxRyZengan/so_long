#include "../include/so_long.h"

int         fill_data_map(int fd, t_map *map)
{
    char    *line;
    int     res;
    int     i;
    int     j;

    line = NULL;
    i = 0;
    res = 1;
    map->map = malloc(sizeof(char *) * (map->line + 1));
    if (!map->map)
        return (0);
    while (i <= map->line)
    {
        map->map[i] = malloc(sizeof(char) * (map->len + 1));
        if (!map->map[i])
            return (0);
        i++;
    }
    i = 0;
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

int         make_data_map(int fd, t_map *map)
{
    char    *line;
    int     ret;
    int     len;
    int     nb_line;

    line = NULL;
    nb_line = 0;
    len = 0;
    ret = 1;
    while (ret != 0)
    {
        ret = get_next_line(fd, &line);
        if (len < ft_strlen(line))
            len = ft_strlen(line);
        nb_line++;
        free(line);
    }
    map->line = nb_line;
    map->len = len;
    return (1);
}

int     check_map_cara_help(t_map *map, int i, int j)
{
    if (map->map[i][j] == 'P')
    {
        map->player.p_x = j;
        map->player.p_y = i;
        map->player.nb_p++;
    }
    else if (map->map[i][j] == 'E')
    {
        map->exit.e_x = j;
        map->exit.e_y = i;
        map->exit.nb_e++;
    }
    else if (map->map[i][j] == 'C')
        map->exit.nb_coll_to_get++;
    else
    {
        if (map->map[i][j] != '1' && map->map[i][j] != '0')
            return (0);
    }
    return (1);
}

int     check_map_cara(t_map *map)
{
    int i;
    int j;

    i = 0;
    map->exit.nb_e = 0;
    map->player.nb_p = 0;
    map->player.nb_coll_get = 0;
    map->exit.nb_coll_to_get = 0;
    map->player.move = 0;
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
    if (map->exit.nb_e != 1 || map->player.nb_p != 1)
        return (0);
    return (1);
}

int     check_map(t_map *map)
{
    int i;

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

int         parser_map(char *str, t_map *map)
{
    int     fd;

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
        return (0);
    return (1);
}