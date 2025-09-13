/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:54:37 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/08 14:07:23 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char const *s, char c)
{
	int	nb;
	int	mode;

	nb = 0;
	mode = 1;
	while (*(s))
	{
		if (mode == 1)
		{
			if (*(s) != c && *(s) != '\n')
			{
				mode = 0;
				nb++;
			}
		}
		else
		{
			if (*(s) == c)
			{
				mode = 1;
			}
		}
		s++;
	}
	return (nb);
}

int	*ft_split_fdf(char const *s, char c, int *row_len)
{
	int	*array;
	int	i;

	if (*(row_len) == -1)
		*(row_len) = count_words(s, c);
	array = malloc(sizeof(int) * *(row_len));
	if (!array)
		return (NULL);
	i = 0;
	while (*(s))
	{
		while (*(s) && *(s) == c)
			s++;
		if (*(s) && *(s) != c && *(s) != '\n')
		{
			*(array + i) = ft_atoi(s);
			i++;
			s++;
		}
		while (*(s) && *(s) != c)
			s++;
	}
	return (array);
}
