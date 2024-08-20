/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:07:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 15:57:16 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**initialize_map(int argc, char **argv, unsigned int size);
void	fill_map(int **map, unsigned int size, char **argv);
void	finalize_map(int **map, unsigned int size);
int		ft_atoi(char *str);

int		**initialize_map(int argc, char **argv, unsigned int size)
{
	int	row;
	int	**map;

	map = (int	**)malloc(sizeof(int *) * (size + 2));
	row = 0;

	while (row++ < size)
		*(map + row) = (int *)malloc(sizeof(int) * (size + 2));

	fill_map(map, size, argv);

	return (map);
}

void	fill_map(int **map, unsigned int size, char **argv)
{
	int	row;
	int	col;

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

void	finalize_map(int **map, unsigned int size)
{
	int row;

	row = -1;
	while (++row < size + 2)
		free(*(map + row));
	free (map);
}

void	print_map(int **map, int size)
{
	int	row;
	int	col;

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
