/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:36:49 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:36:52 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

typedef struct s_player
{
	int	p_x;
	int	p_y;
	int	nb_p;
	int	n_c_g;
	int	move;
}		t_player;

typedef struct s_exit
{
	int	e_x;
	int	e_y;
	int	nb_e;
	int	n_c_t_g;
}		t_exit;

typedef struct s_map
{
	char		**map;
	int			line;
	int			len;
	t_player	p;
	t_exit		exit;
}		t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr_img;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_texture
{
	void	*f;
	void	*p;
	void	*e_o;
	void	*e_c;
	void	*w;
	void	*c;
}		t_texture;

typedef struct s_data
{
	int			w_h;
	int			w_w;
	int			w_r;
	void		*m_p;
	void		*w_p;
	t_map		map;
	t_img		img;
	t_texture	tex;
}		t_data;

int		ft_strlen(char const *str);
void	*ft_memcpy(void *dest, void *src, size_t size);
char	*ft_strdup(char const *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);
int		parser_map(char *str, t_map *map);
int		window_size(t_data *data);
void	get_texture(t_data *data);
void	do_map(t_data *data);
int		keyboard_gestion(int touch, t_data *data);
void	do_wall(t_data *data);
void	do_floor(t_data *data);
void	do_pce(t_data *data);
int		free_game(t_data *data);
int		check_name(char *str);
int		fill_data_map(int fd, t_map *map);

#endif
