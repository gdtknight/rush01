/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:22:22 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 20:52:26 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	is_valid_args(int argc, char **argv)
{
	int				valid;
	unsigned int	size;
	int				n;

	valid = 0;
	size = 3;
	while (++size < 10)
	{
		if (((unsigned int)argc - 1) == size * 4)
		{
			valid = 1;
			break ;
		}
	}
	while (*(++argv))
	{
		n = ft_atoi(*argv);
		if (n < 1 && size < (unsigned int)n)
			return (0);
	}
	return (valid);
}

int	is_valid_map(unsigned int **map, unsigned int size)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (++row <= size)
	{
		if (!is_valid_row(map, size, row))
			return (0);
	}
	col = 0;
	while (++col <= size)
	{
		if (!is_valid_col(map, size, col))
			return (0);
	}
	return (1);
}

/* rowleft : map[row][0] */
/* rowright : map[row][size + 1] */
int	is_valid_row(unsigned int **map, unsigned int size, unsigned int row)
{
	unsigned int	col;
	unsigned int	c;
	unsigned int	visible;

	col = 0;
	while (++col < size)
	{
		c = col;
		while (++c <= size)
			if (map[row][col] == map[row][c])
				return (0);
	}
	col = 1;
	c = col;
	visible = 0;
	if (map[row][c] != 0)
		visible++;
	while (++col <= size)
	{
		if (map[row][c] < map[row][col])
		{
			visible++;
			c = col;
		}
	}
	if (map[row][0] < visible)
		return (0);
	col = size;
	c = col;
	visible = 0;
	if (map[row][c] != 0)
		visible++;
	while (1 <= --col)
	{
		if (map[row][c] < map[row][col])
		{
			visible++;
			c = col;
		}
	}
	if (visible > map[row][size + 1])
		return (0);
	return (1);
}

/* colup : map[0][col] */
/* coldown : map[size + 1][col] */
int	is_valid_col(unsigned int **map, unsigned int size, unsigned int col)
{
	unsigned int	row;
	unsigned int	r;
	unsigned int	visible;

	row = 0;
	while (++row < size)
	{
		r = row;
		while (++r <= size)
			if (map[row][col] == map[r][col])
				return (0);
	}
	row = 1;
	r = row;
	visible = 0;
	if (map[r][col] != 0)
		visible++;
	while (++row <= size)
	{
		if (map[r][col] < map[row][col])
		{
			visible++;
			r = row;
		}
	}
	if (map[0][col] < visible)
		return (0);
	row = size;
	r = row;
	visible = 0;
	if (map[r][col] != 0)
		visible++;
	while (1 <= --row)
	{
		if (map[r][col] < map[row][col])
		{
			visible++;
			r = row;
		}
	}
	if (visible > map[size + 1][col])
		return (0);
	return (1);
}
