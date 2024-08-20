/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:07:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 20:54:03 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

unsigned int	**initialize_map(char **argv, unsigned int size)
{
	unsigned int	row;
	unsigned int	**map;

	map = (unsigned int **)malloc(sizeof(unsigned int *) * (size + 2));
	row = 0;
	while (row++ < size)
		*(map + row) = (unsigned int *)malloc(sizeof(unsigned int) * (size + 2));
	fill_map(map, size, argv);
	return (map);
}

void	fill_map(unsigned int **map, unsigned int size, char **argv)
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
		map[0][col] = ft_atoi(argv[col]);
		map[size + 1][col] = ft_atoi(argv[col + size]);
	}
	row = 0;
	while (++row <= size)
	{
		map[row][0] = ft_atoi(argv[row + size * 2]);
		map[row][size + 1] = ft_atoi(argv[row + size * 3]);
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
	col = 0;
	while (++row <= size)
	{
		while (++col <= size)
		{
			write(1, &map[row][col], 1);
			if (col != size)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
