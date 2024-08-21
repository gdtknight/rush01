/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:22:22 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:07:51 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_row.h"

/* rowleft : map[row][0] */
/* rowright : map[row][size + 1] */
int	is_valid_row(unsigned int **map, unsigned int size, unsigned int row)
{
	if (!is_unique_row(map, size, row))
		return (0);
	if (!is_valid_rowleft(map, size, row))
		return (0);
	if (!is_valid_rowright(map, size, row))
		return (0);
	return (1);
}

int	is_unique_row(unsigned int **map, unsigned int size, unsigned int row)
{
	unsigned int	col;
	unsigned int	c;

	col = 0;
	while (++col < size)
	{
		if (map[row][col] == 0)
			break ;
		c = col;
		while (++c <= size)
		{
			if (map[row][c] == 0)
				break ;
			if (map[row][col] != 0
				&& map[row][c] != 0
				&& map[row][col] == map[row][c])
				return (0);
		}
	}
	return (1);
}

int	is_valid_rowleft(unsigned int **map, unsigned int size, unsigned int row)
{
	unsigned int	col;
	unsigned int	c;
	unsigned int	visible;

	col = 1;
	c = col;
	visible = 0;
	if (map[row][c] != 0)
		visible++;
	while (++col <= size)
	{
		if (map[row][col] == 0)
			break ;
		if (map[row][c] < map[row][col])
		{
			visible++;
			c = col;
		}
		if ((map[row][c] == size && visible != map[row][0])
			|| (map[row][c] != size && visible == map[row][0]))
			return (0);
	}
	return (1);
}

int	is_valid_rowright(unsigned int **map, unsigned int size, unsigned int row)
{
	unsigned int	col;
	unsigned int	c;
	unsigned int	visible;

	col = size;
	c = col;
	visible = 0;
	if (map[row][c] == 0)
		return (1);
	if (map[row][c] != 0)
		visible++;
	while (1 <= --col)
	{
		if (map[row][col] == 0)
			return (1);
		if (map[row][c] < map[row][col])
		{
			visible++;
			c = col;
		}
		if ((map[row][c] == size && visible != map[row][size + 1])
			|| (map[row][c] != size && visible == map[row][size + 1]))
			return (0);
	}
	return (1);
}
