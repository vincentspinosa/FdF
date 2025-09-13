/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:33:00 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/13 18:48:00 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx_linux/mlx.h"

# define WIN_W 3000
# define WIN_H 2000
# define ESC 65307
# define DESTROY 17
# define Z_B_V 500

typedef struct s_point_3d
{
	int	x;
	int	y;
	int	z;
}		t_point_3d;

typedef struct s_point_2d
{
	float	x;
	float	y;
}			t_point_2d;

typedef struct s_delta
{
	float	d_x;
	float	d_y;
}			t_delta;

typedef struct s_traversal_handler
{
	int	i;
	int	i_x;
	int	i_y;
}		t_th;

typedef struct s_th_dda
{
	int		i;
	float	x;
	float	y;
}			t_thd;

/*
i2d : int array in 2 dimensions
p3 : points 3d
p2 : points 2d
bpp : bits per pixel
ll : line len
nd : endian
*/
typedef struct s_state
{
	const char	*map_path;
	int			map_w;
	int			map_h;
	int			**i2d;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*img_addr;
	t_point_3d	*p3;
	t_point_2d	*p2;
	float		zoom;
	int			bpp;
	int			ll;
	int			nd;
}				t_state;

typedef struct s_array_maker
{
	int		fd;
	char	*temp_str;
	int		*row;
}			t_array_maker;

/*
hooks.c
*/
void	hooks(t_state *s);

/*
make_line.c
*/
void	make_line(t_state *s, t_point_2d pt_a, t_point_2d pt_b);

/*
make_map_array.c
*/
void	make_map_array(t_state *s);

/*
points.c
*/
void	make_3d_points(t_state *s);
void	make_2d_points(t_state *s);

/*
traversal.c
*/
void	connect_points(t_state *s);

/*
---------------------------------------
---------------------------------------
---------------------------------------
				HELPERS
---------------------------------------
---------------------------------------
---------------------------------------
*/

/*
array_helpers.c
*/
int		**append_2d(int **array, int *el, int size, t_state *s);

/*
ft_split.c
*/
int		count_words(char const *s, char c);
int		*ft_split_fdf(char const *s, char c, int *row_len);

/*
get_next_line.c
*/
char	*get_next_line(int fd);

/*
len_functions.c
*/
int		ft_strlen(const char *str);

/*
parsing.c
*/
int		ft_atoi(const char *str);

/*
print_functions.c
*/
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_putarr(int *array, int size);
void	ft_putmap(int **array, int size, int row_len);
void	print_point_3d(t_point_3d *point, int i);

/*
termination.c
*/
void	ft_pterr_ext(const char *str);
void	free_all_char(char **array, int len);
void	free_all_int(int **array, int len);
void	free_mlx(t_state *s, int lvl, int malloc_);

#endif
