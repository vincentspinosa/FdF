/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:05:39 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/10 18:16:06 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid(int n, int limit)
{
	if (n > -1 && n < limit)
		return (1);
	return (0);
}

static void	mod_px(t_state *s, int x, int y, int c)
{
	char	*px;

	if (is_valid(x, WIN_W) && (is_valid(y, WIN_H)))
	{
		px = s->img_addr + ((y * s->ll) + (x * (s->bpp / 8)));
		*(unsigned int *)px = c;
	}
}

void	make_line(t_state *s, t_point_2d pt_a, t_point_2d pt_b)
{
	t_delta		d_total;
	t_delta		d_step;
	float		nb_steps;
	t_thd		thd;

	d_total.d_x = pt_b.x - pt_a.x;
	d_total.d_y = pt_b.y - pt_a.y;
	if (fabsf(d_total.d_x) >= fabsf(d_total.d_y))
		nb_steps = fabsf(d_total.d_x);
	else
		nb_steps = fabsf(d_total.d_y);
	d_step.d_x = d_total.d_x / nb_steps;
	d_step.d_y = d_total.d_y / nb_steps;
	thd.x = pt_a.x;
	thd.y = pt_a.y;
	thd.i = 0;
	while (thd.i < nb_steps)
	{
		mod_px(s, (-thd.x + (WIN_W / 2)), (-thd.y + (WIN_H / 2)), 0xFFFFFF);
		thd.x += d_step.d_x;
		thd.y += d_step.d_y;
		thd.i++;
	}
}
