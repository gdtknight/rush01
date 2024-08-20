/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:57:41 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 02:24:42 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
// #include "ft_putnbr.h"
// #include "map.h"

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

	/* Debug */
	// write(1, "\n===== Recursive ", 17);
	// write(1, "(f_count : ", 11);
	// ft_putnbr(f_count);
	// write(1, ") =====\n", 8);
	/* ----- */

	row = f_count / size + 1;
	col = f_count % size + 1;
	num = 0;
	while (++num <= size)
	{
		/* Debug */
		// write(1, "Current Number : ", 17);
		// ft_putnbr(num);
		// write(1, "\n", 1);
		/* ----- */

		map[row][col] = num;
		if (!is_valid_row(map, size, row) || !is_valid_col(map, size, col))
			continue;

		/* Debug */
		// ft_putnbr(num);
		// write(1, " is Ok !\n", 9);
		// write(1, "\n", 1);
		// print_all_map(map, size);
		// write(1, "\n", 1);
		/* ------- */

		if(__recursive__(map, size, f_count + 1))
			return(1);
	}
	map[row][col] = 0;

	/* Debug */
	// write(1, "\n===== Recursive ", 17);
	// write(1, "(f_count : ", 11);
	// ft_putnbr(f_count);
	// write(1, ") - Fail =====\n", 15);
	/* ----- */

	return (0);
}
