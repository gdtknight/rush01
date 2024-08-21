/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:57:41 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:25:01 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"

int	find_solution(unsigned int **map, unsigned int size)
{
	fill_highest_row(map, size);
	fill_highest_col(map, size);
	fill_first_highest_box(map, size);
	fill_ordered_row(map, size);
	fill_ordered_col(map, size);
	return (__recursive__(map, size, 0));
}

int	__recursive__(unsigned int **map, unsigned int size, unsigned int f_count)
{
	unsigned int	max;
	unsigned int	num;
	unsigned int	row;
	unsigned int	col;

	if (f_count == (size * size))
		return (1);
	row = f_count / size + 1;
	col = f_count % size + 1;
	if (map[row][col] != 0)
		return (__recursive__(map, size, f_count + 1));
	max = size;
	if (map[0][col] > row && size > (map[0][col] - row))
		max = size - (map[0][col] - row);
	num = 0;
	while (++num <= max)
	{
		map[row][col] = num;
		if (!is_valid_row(map, size, row) || !is_valid_col(map, size, col))
			continue ;
		if (__recursive__(map, size, f_count + 1))
			return (1);
	}
	map[row][col] = 0;
	return (0);
}
