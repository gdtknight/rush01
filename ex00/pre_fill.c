/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:12:38 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:25:48 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pre_fill.h"

void	fill_first_highest_box(unsigned int **map, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (++idx <= size)
	{
		if (map[idx][0] == 1)
			map[idx][1] = size;
		if (map[idx][size + 1] == 1)
			map[idx][size] = size;
		if (map[0][idx] == 1)
			map[1][idx] = size;
		if (map[size + 1][idx] == 1)
			map[size][idx] = size;
	}
}

/* colup    : map[0][col]        */
/* coldown  : map[size + 1][col] */
/* rowleft  : map[row][0]        */
/* rowright : map[row][size + 1] */
void	fill_highest_row(unsigned int **map, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (++idx <= size)
	{
		if (map[idx][0] + map[idx][size + 1] == size + 1)
			map[idx][map[idx][0]] = size;
		if (map[idx][0] + map[idx][size + 1] == 3)
		{
			if (map[idx][0] < map[idx][size + 1])
			{
				map[idx][1] = size;
				map[idx][size] = size - 1;
			}
			else
			{
				map[idx][1] = size - 1;
				map[idx][size] = size;
			}
		}
	}
}

void	fill_highest_col(unsigned int **map, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (++idx <= size)
	{
		if (map[0][idx] + map[size + 1][idx] == size + 1)
			map[map[0][idx]][idx] = size;
		if (map[0][idx] + map[size + 1][idx] == 3)
		{
			if (map[0][idx] < map[size + 1][idx])
			{
				map[1][idx] = size;
				map[size][idx] = size - 1;
			}
			else
			{
				map[1][idx] = size - 1;
				map[size][idx] = size;
			}
		}
	}
}

void	fill_ordered_row(unsigned int **map, unsigned int size)
{
	unsigned int	idx;
	unsigned int	row;

	idx = 0;
	while (++idx <= size)
	{
		if (map[0][idx] == size)
		{
			row = 0;
			while (++row <= size)
				map[row][idx] = row;
		}
		if (map[size + 1][idx] == size)
		{
			row = size + 1;
			while (--row >= 1)
				map[row][idx] = size + 1 - row;
		}
	}
}

void	fill_ordered_col(unsigned int **map, unsigned int size)
{
	unsigned int	idx;
	unsigned int	col;

	idx = 0;
	while (++idx <= size)
	{
		if (map[idx][0] == size)
		{
			col = 0;
			while (++col <= size)
				map[idx][col] = col;
		}
		if (map[idx][size + 1] == size)
		{
			col = size + 1;
			while (--col >= 1)
				map[idx][col] = size + 1 - col;
		}
	}
}
