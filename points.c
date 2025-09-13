/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:51:32 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/10 17:51:38 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_3d_points(t_state *s)
{
	t_th	th;
	int		len;

	len = s->map_h * s->map_w;
	s->p3 = malloc(sizeof(t_point_3d) * len);
	if (!(s->p3))
		return (free_all_int(s->i2d, s->map_h), ft_pterr_ext("Malloc failed."));
	th.i = 0;
	th.i_y = 0;
	while (th.i_y < s->map_h)
	{
		th.i_x = 0;
		while (th.i_x < s->map_w)
		{
			s->p3[th.i].x = th.i_x;
			s->p3[th.i].y = th.i_y;
			s->p3[th.i].z = s->i2d[th.i_y][th.i_x];
			th.i++;
			th.i_x++;
		}
		th.i_y++;
	}
	free_all_int(s->i2d, th.i_y);
}

void	make_2d_points(t_state *s)
{
	int	i;
	int	len;

	len = s->map_h * s->map_w;
	s->p2 = malloc(sizeof(t_point_2d) * len);
	if (!(s->p2))
	{
		free(s->p3);
		ft_pterr_ext("Malloc failed.");
	}
	i = 0;
	while (i < len)
	{
		s->p2[i].x = -(s->p3[i].x * cosf(120)) + (s->p3[i].y * cosf(120 + 2))
			+ (s->p3[i].z * cosf(120 - 2));
		s->p2[i].y = -(s->p3[i].x * sinf(120)) + (sinf(120 + 2) * s->p3[i].y)
			+ (sinf(120 - 2) * s->p3[i].z);
		s->p2[i].x *= s->zoom;
		s->p2[i].y *= -s->zoom;
		i++;
	}
	free(s->p3);
}
