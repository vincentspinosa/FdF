/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:12:03 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/02 14:00:17 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "unistd.h"
# include "stdlib.h"

/*
br : servira a stocker les bytes lus pendant read
x : un int a notre disposition
b : buffer
bs : buffer save
l : ligne a retourner
ts : temp str
*/
typedef struct s_NextLineReader
{
	int			br;
	int			x;
	char		b[BUFFER_SIZE + 1];
	char		bs[BUFFER_SIZE + 1];
	char		*l;
	char		*ts;
}				t_NextLineReader;

char	*get_next_line(int fd);
int		strlengnl(char *str);
int		contains_newline(char *str);
char	*ft_strtrim_keep_before(char *str, int end);
char	*ft_strtrim_keep_after(char *str, int start);
void	ft_strcpy_buffer(char *buffer, char *str, int start, int end);

#endif
