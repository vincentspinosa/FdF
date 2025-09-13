/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:25:57 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/13 17:25:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**append_2d(int **array, int *el, int size, t_state *s)
{
	int	i;
	int	**new_arr;

	new_arr = malloc(sizeof(int *) * (size + 1));
	if (!new_arr)
	{
		free_all_int(array, s->map_h);
		ft_pterr_ext("Malloc failed.");
	}
	i = 0;
	while (i < size)
	{
		new_arr[i] = array[i];
		i++;
	}
	new_arr[i] = el;
	free(array);
	return (new_arr);
}
