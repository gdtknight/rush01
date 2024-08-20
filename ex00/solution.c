/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:57:41 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 08:40:51 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "ft_putnbr.h"
#include "map.h"

int	find_solution(unsigned int **map, unsigned int size)
{
	__fill_highest_box__(map,  size);
	__fill_ordered_box__(map, size);
	return (__recursive__(map, size, 0));
}


/* colup : map[0][col] */
/* coldown : map[size + 1][col] */
/* rowleft : map[row][0] */
/* rowright : map[row][size + 1] */
void  __fill_highest_box__(unsigned int **map, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (++idx <= size)
	{
		// rowleft + rowright = size + 1
		if (map[idx][0] + map[idx][size + 1] == size + 1)
			map[idx][map[idx][0]] = size;
		if (map[0][idx] + map[size + 1][idx] == size + 1)
			map[map[0][idx]][idx] = size;
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

void  __fill_ordered_box__(unsigned int **map, unsigned int size)
{
	unsigned int	idx;
	unsigned int	row;
	unsigned int	col;

	idx = 0;
	while (++idx <= size)
	{
		// colup
		if (map[0][idx] == size)
		{
			row = 0;
			while (++row <= size)
				map[row][idx] = row;
		}
		// coldown
		if (map[size + 1][idx] == size)
		{
			row = size + 1;
			while (--row >= 1)
				map[row][idx] = size + 1 - row;
		}
		// rowleft
		if (map[idx][0] == size)
		{
			col = 0;
			while (++col <= size)
				map[idx][col] = col;
		}
		// rowright
		if (map[idx][size + 1] == size)
		{
			col = size + 1;
			while (--col >= 1)
				map[idx][col] = size + 1 - col;
		}
	}
}

int	__recursive__(unsigned int **map, unsigned int size, unsigned int f_count)
{
	unsigned int	min;
	unsigned int	max;
	unsigned int	num;
	unsigned int	row;
	unsigned int	col;

	if (f_count == (size * size))
		return (1);

	/* Debug */
	write(1, "\n===== Recursive ", 17);
	write(1, "(f_count : ", 11);
	ft_putnbr(f_count);
	write(1, ") =====\n", 8);
	/* ----- */

	row = f_count / size + 1;
	col = f_count % size + 1;

	if (map[row][col] != 0)
	{
		print_all_map(map, size);
		if(__recursive__(map, size, f_count + 1))
			return (1);
		else
			return (0);
	}
	min = 1;
	max = size;
	if (map[0][col] > row)
		max = size - (map[0][col] - row);

	num = min - 1;
	while (++num <= max)
	{
		/* Debug */
		write(1, "Current Number : ", 17);
		ft_putnbr(num);
		write(1, "\n", 1);
		/* ----- */

		map[row][col] = num;
		if (!is_valid_row(map, size, row) || !is_valid_col(map, size, col))
			continue;

		/* Debug */
		ft_putnbr(num);
		write(1, " is Ok !\n", 9);
		write(1, "\n", 1);
		print_all_map(map, size);
		write(1, "\n", 1);
		/* ------- */

		if(__recursive__(map, size, f_count + 1))
			return (1);
	}
	map[row][col] = 0;

	/* Debug */
	write(1, "===== Recursive ", 17);
	write(1, "(f_count : ", 11);
	ft_putnbr(f_count);
	write(1, ") - Fail =====\n", 15);
	/* ----- */

	return (0);
}
