/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:52:29 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/02 13:59:58 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *previous_line, char *buff, int del)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	len = strlengnl(previous_line) + strlengnl(buff);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*(previous_line + i))
	{
		*(str + i) = *(previous_line + i);
		i++;
	}
	j = 0;
	while (*(buff + j))
	{
		*(str + i + j) = *(buff + j);
		j++;
	}
	*(str + i + j) = '\0';
	if (del == 1)
		free(previous_line);
	return (str);
}

static char	*part_b(int fd, t_NextLineReader *nlr)
{
	while (1)
	{
		nlr->br = read(fd, nlr->b, BUFFER_SIZE);
		if (nlr->br < 1)
			break ;
		nlr->b[nlr->br] = '\0';
		nlr->x = contains_newline(nlr->b);
		if (nlr->x != -1)
		{
			nlr->ts = ft_strtrim_keep_before(nlr->b, nlr->x + 1);
			nlr->l = ft_strjoin(nlr->l, nlr->ts, 1);
			free(nlr->ts);
			nlr->ts = ft_strtrim_keep_after(nlr->b, nlr->x + 1);
			if (!nlr->ts || !nlr->l)
				return (NULL);
			ft_strcpy_buffer(nlr->bs, nlr->ts, 0, strlengnl(nlr->ts));
			free(nlr->ts);
			return (nlr->l);
		}
		nlr->l = ft_strjoin(nlr->l, nlr->b, 1);
	}
	if (strlengnl(nlr->l) > 0 && nlr->br != -1)
		return (nlr->l);
	free(nlr->l);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_NextLineReader	nlr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nlr.x = contains_newline(nlr.bs);
	if (nlr.x != -1)
	{
		nlr.l = ft_strtrim_keep_before(nlr.bs, nlr.x + 1);
		nlr.ts = ft_strtrim_keep_after(nlr.bs, nlr.x + 1);
		if (!nlr.ts || !nlr.l)
			return (NULL);
		ft_strcpy_buffer(nlr.bs, nlr.ts, 0, strlengnl(nlr.ts));
		free(nlr.ts);
		return (nlr.l);
	}
	nlr.l = ft_strjoin("", nlr.bs, -1);
	*(nlr.bs) = '\0';
	return (part_b(fd, &nlr));
}

/////////////////////////////////////////////////////////////
// FOR TESTING ONLY
/////////////////////////////////////////////////////////////

/*
#include "fcntl.h"

void	TEST_ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		write(1, (str + i), 1);
		i++;
	}
}


int		main(int ac, char **argv)
{	
	char	*str;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
		TEST_ft_putstr(str);
	close(fd);
}*/
