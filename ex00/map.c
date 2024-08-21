/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:07:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 20:22:24 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_putnbr.h"

unsigned int	**initialize_map(char *argv, unsigned int size)
{
	unsigned int	row;
	unsigned int	**map;

	map = (unsigned int **)malloc(sizeof(unsigned int *) * (size + 2));
	row = -1;
	while (++row < size + 2)
		*(map + row) = \
			(unsigned int *)malloc(sizeof(unsigned int) * (size + 2));
	fill_map(map, size, argv);
	return (map);
}

void	fill_map(unsigned int **map, unsigned int size, char *argv)
{
	unsigned int	row;
	unsigned int	col;

	row = -1;
	while (++row < size + 2)
	{
		col = -1;
		while (++col < size + 2)
			map[row][col] = 0;
	}
	col = 0;
	while (++col <= size)
	{
		map[0][col] = argv[col - 1] - '0';
		map[size + 1][col] = argv[col + size - 1] - '0';
	}
	row = 0;
	while (++row <= size)
	{
		map[row][0] = argv[row + size * 2 - 1] - '0';
		map[row][size + 1] = argv[row + size * 3 - 1] - '0';
	}
}

void	finalize_map(unsigned int **map, unsigned int size)
{
	unsigned int	row;

	row = -1;
	while (++row < size + 2)
		free(*(map + row));
	free (map);
}

void	print_map(unsigned int **map, unsigned int size)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (++row <= size)
	{
		col = 0;
		while (++col <= size)
		{
			ft_putnbr(map[row][col]);
			if (col != size)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void	print_all_map(unsigned int **map, unsigned int size)
{
	unsigned int	row;
	unsigned int	col;

	row = -1;
	while (++row <= size + 1)
	{
		col = -1;
		while (++col <= size + 1)
		{
			ft_putnbr(map[row][col]);
			if (col != size + 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
