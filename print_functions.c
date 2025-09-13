/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:02:24 by vispinos          #+#    #+#             */
/*   Updated: 2024/07/08 18:28:52 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr(const char *str)
{
	while (*(str))
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	c = n + '0';
	write(1, &c, 1);
}

void	ft_putarr(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		ft_putstr(" ");
		i++;
	}
}

void	ft_putmap(int **array, int size, int row_len)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putarr(array[i], row_len);
		ft_putstr("\n");
		i++;
	}
}

void	print_point_3d(t_point_3d *point, int i)
{
	ft_putstr("Point ");
	ft_putnbr(i);
	ft_putstr("\n");
	ft_putstr("x ");
	ft_putnbr(point->x);
	ft_putstr("\n");
	ft_putstr("y ");
	ft_putnbr(point->y);
	ft_putstr("\n");
	ft_putstr("z ");
	ft_putnbr(point->z);
	ft_putstr("\n");
}
