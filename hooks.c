/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:50:38 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/13 17:06:05 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_destroy(t_state *s)
{
	if (s->mlx)
	{
		free_mlx(s, 3, 0);
		exit(0);
		return (1);
	}
	return (0);
}

static int	esc_destroy(int key, t_state *s)
{
	if (key == ESC)
	{	
		ft_destroy(s);
		return (1);
	}
	return (0);
}

void	hooks(t_state *s)
{
	mlx_key_hook(s->mlx_win, esc_destroy, s);
	mlx_hook(s->mlx_win, DESTROY, 0, ft_destroy, s);
}
