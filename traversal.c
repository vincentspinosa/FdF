/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:50:23 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/04 16:08:28 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	connect_right(t_state *s, t_th *th)
{
	make_line(s, s->p2[th->i], s->p2[th->i + 1]);
	th->i_x++;
}

static void	connect_bottom(t_state *s, t_th *th)
{
	make_line(s, s->p2[th->i], s->p2[th->i + s->map_w]);
}

static void	connect_both(t_state *s, t_th *th)
{
	connect_right(s, th);
	connect_bottom(s, th);
	th->i++;
}

void	connect_points(t_state *s)
{
	t_th	th;

	th.i_y = 0;
	th.i = 0;
	while (th.i_y < s->map_h - 1)
	{
		th.i_x = 0;
		while (th.i_x < s->map_w - 1)
			connect_both(s, &th);
		connect_bottom(s, &th);
		th.i++;
		th.i_y++;
	}
	th.i_x = 0;
	while (th.i_x < s->map_w - 1)
	{
		connect_right(s, &th);
		th.i++;
	}
	free(s->p2);
}
