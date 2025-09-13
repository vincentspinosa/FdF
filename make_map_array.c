/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:37:25 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/13 17:08:12 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	open_and_check(t_state *s, t_array_maker *am)
{
	am->fd = open(s->map_path, O_RDONLY);
	if (am->fd == -1)
	{
		close(am->fd);
		ft_pterr_ext("Error: could not open file given as argument.\n");
	}
}

void	make_map_array(t_state *s)
{
	t_array_maker	am;

	open_and_check(s, &am);
	s->i2d = NULL;
	s->map_w = -1;
	s->map_h = 0;
	while (1)
	{
		am.temp_str = get_next_line(am.fd);
		if (!(am.temp_str))
			break ;
		am.row = ft_split_fdf(am.temp_str, ' ', &(s->map_w));
		if (s->map_w == -1)
			s->map_w = count_words(am.temp_str, ' ');
		free(am.temp_str);
		if (!(am.row))
		{
			close(am.fd);
			free_all_int(s->i2d, s->map_h);
			ft_pterr_ext("Malloc failed.\n");
		}
		s->i2d = append_2d(s->i2d, am.row, s->map_h, s);
		s->map_h++;
	}
	close(am.fd);
}
