/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:36:03 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/13 19:02:55 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pterr_ext(const char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	free_all_char(char **array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(array + i);
		i++;
	}
	free(array);
}

void	free_all_int(int **array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_mlx(t_state *s, int lvl, int malloc_)
{
	if (lvl > 2)
		mlx_destroy_image(s->mlx, s->mlx_img);
	if (lvl > 1)
		mlx_destroy_window(s->mlx, s->mlx_win);
	if (lvl > 0)
	{
		mlx_destroy_display(s->mlx);
		free(s->mlx);
	}
	if (malloc_ == 1)
		ft_pterr_ext("Malloc failed.");
}
