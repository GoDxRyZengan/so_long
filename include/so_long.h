#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 42

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF

typedef struct  s_player
{
    int         p_x;
    int         p_y;
    int         nb_p;
    int         nb_coll_get;
    int         move;
}               t_player;

typedef struct  s_exit
{
    int         e_x;
    int         e_y;
    int         nb_e;
    int         nb_coll_to_get;
}               t_exit;

typedef struct  s_map
{
    char        **map;
    int         line;
    int         len;
    t_player    player;
    t_exit      exit;
}               t_map;

typedef struct s_img
{
    void        *img_ptr;
    char        *addr_img;
    int         bpp;
    int         line_len;
    int         endian;
}               t_img;

typedef struct  s_texture
{
    void        *floor;
    void        *player;
    void        *exit_open;
    void        *exit_close;
    void        *wall;
    void        *coll;
}               t_texture;

typedef struct  s_data
{
    int         win_height;
    int         win_width;
    int         win_ratio;
    void        *mlx_ptr;
    void        *win_ptr;
    t_map       map;
    t_img       img;
    t_texture   texture;
}               t_data;




int     ft_strlen(char const *str);
void	*ft_memcpy(void *dest, void *src, size_t size);
char	*ft_strdup(char const *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int	    get_next_line(int fd, char **line);
int     parser_map(char *str, t_map *map);
int     window_size(t_data *data);
void    get_texture(t_data *data);
void    do_map(t_data *data);
int     keyboard_action(int touch, t_data *data);
void        do_wall(t_data *data);
void        do_floor(t_data *data);
void        do_pce(t_data *data);
int     free_game(t_data *data);

#endif
