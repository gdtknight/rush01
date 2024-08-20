/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:57:41 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 20:57:06 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"

int	find_solution(unsigned int **map, unsigned int size)
{
	return (__recursive__(map, size, 0));
}

int	__recursive__(unsigned int **map, unsigned int size, unsigned int f_count)
{
	unsigned int	num;
	unsigned int	row;
	unsigned int	col;

	if (f_count == (size * size))
	{
		if (is_valid_map(map, size))
			return (1);
		else
			return (0);
	}
	row = f_count / size + 1;
	col = f_count % size + 1;
	num = 1;
	while (num <= 4)
	{
		map[row][col] = num;
		if (!is_valid_row(map, size, row) && !is_valid_col(map, size, col))
			continue;
		if(__recursive__(map, size, f_count + 1))
			return(1);
	}
	return (0);
}
