/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:33:45 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/13 18:55:46 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_points(t_state *s, char **av)
{
	s->map_path = av[1];
	make_map_array(s);
	make_3d_points(s);
}

static int	show_img(t_state *s)
{
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->mlx_img, 0, 0);
	return (0);
}

static float	compute_zoom(t_state *s)
{
	if (!s->map_w || !s->map_h)
		return (1);
	if (s->map_w > s->map_h)
		return (Z_B_V / s->map_w);
	return (Z_B_V / s->map_h);
}

static int	make_img(t_state *s)
{
	s->mlx = mlx_init();
	if (!(s->mlx))
		(free(s->p2), ft_pterr_ext("Malloc failed."));
	s->mlx_win = mlx_new_window(s->mlx, WIN_W, WIN_H, "vispinos's FdF");
	if (!(s->mlx_win))
		(free(s->p2), free_mlx(s, 1, 1));
	s->mlx_img = mlx_new_image(s->mlx, WIN_W, WIN_H);
	if (!(s->mlx_img))
		(free(s->p2), free_mlx(s, 2, 1));
	s->img_addr = mlx_get_data_addr(s->mlx_img, &s->bpp, &s->ll, &s->nd);
	if (!(s->img_addr))
		(free(s->p2), free_mlx(s, 3, 1));
	s->zoom = compute_zoom(s);
	make_2d_points(s);
	connect_points(s);
	hooks(s);
	mlx_loop_hook(s->mlx, show_img, s);
	mlx_loop(s->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_state	s;

	if (ac != 2)
		ft_pterr_ext("Error: format expected is:\n./fdf <file.fdf>\n");
	get_points(&s, av);
	make_img(&s);
}
