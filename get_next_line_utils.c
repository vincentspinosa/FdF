/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:55:40 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/02 14:00:11 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strlengnl(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	contains_newline(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strtrim_keep_after(char *str, int start)
{
	int				len;
	int				i;
	char			*s2;

	len = strlengnl(str + start);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(s2 + i) = *(str + start + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

char	*ft_strtrim_keep_before(char *str, int end)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	while (*(str + len) && len < end)
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(s2 + i) = *(str + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

void	ft_strcpy_buffer(char *buffer, char *str, int start, int end)
{
	int	i;
	int	len;

	len = 0;
	while (*(str + len + start) && (len + start) < end)
		len++;
	i = 0;
	while (i < len)
	{
		*(buffer + i) = *(str + start + i);
		i++;
	}
	*(buffer + i) = '\0';
}
