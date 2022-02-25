#include "../include/so_long.h"

int     main(int argc, char **argv)
{
    t_data  data; 

//   if (argc != 2 || (check_map_file(argv[1])) == 0)
    if (argc != 2)
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