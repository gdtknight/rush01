/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:22:22 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:05:55 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_col.h"

/* colup : map[0][col] */
/* coldown : map[size + 1][col] */
int	is_valid_col(unsigned int **map, unsigned int size, unsigned int col)
{
	if (!is_unique_col(map, size, col))
		return (0);
	if (!is_valid_colup(map, size, col))
		return (0);
	if (!is_valid_coldown(map, size, col))
		return (0);
	return (1);
}

int	is_unique_col(unsigned int **map, unsigned int size, unsigned int col)
{
	unsigned int	row;
	unsigned int	r;

	row = 0;
	while (++row < size)
	{
		if (map[row][col] == 0)
			break ;
		r = row;
		while (++r <= size)
		{
			if (map[r][col] == 0)
				break ;
			if (map[row][col] != 0
				&& map[r][col] != 0
				&& map[row][col] == map[r][col])
				return (0);
		}
	}
	return (1);
}

int	is_valid_colup(unsigned int **map, unsigned int size, unsigned int col)
{
	unsigned int	row;
	unsigned int	r;
	unsigned int	visible;

	r = 1;
	row = 1;
	visible = 0;
	if (map[r][col] != 0)
		visible++;
	while (++row <= size)
	{
		if (map[row][col] == 0)
			break ;
		if (map[r][col] < map[row][col])
		{
			visible++;
			r = row;
		}
		if ((map[r][col] == size && visible != map[0][col])
			|| (map[r][col] != size && visible == map[0][col]))
			return (0);
	}
	return (1);
}

int	is_valid_coldown(unsigned int **map, unsigned int size, unsigned int col)
{
	unsigned int	row;
	unsigned int	r;
	unsigned int	visible;

	row = size;
	r = row;
	visible = 0;
	if (map[r][col] == 0)
		return (1);
	if (map[r][col] != 0)
		visible++;
	while (1 <= --row)
	{
		if (map[row][col] == 0)
			return (1);
		if (map[r][col] < map[row][col])
		{
			visible++;
			r = row;
		}
		if ((map[r][col] == size && visible != map[size + 1][col])
			|| (map[r][col] != size && visible == map[size + 1][col]))
			return (0);
	}
	return (1);
}
