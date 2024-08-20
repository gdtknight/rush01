/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:47:32 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 15:34:42 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  argv[0] : ./rush-01
 *  argv[1] : col1up
 *  argv[2] : col2up
 *  argv[3] : col3up
 *  argv[4] : col4up
 *  argv[5] : col1down
 *  argv[6] : col2down
 *  argv[7] : col3down 
 *  argv[8] : col4down
 *  argv[9] : row1left
 * argv[10] : row2left
 * argv[11] : row3left
 * argv[12] : row4left
 * argv[13] : row1right
 * argv[14] : row2right
 * argv[15] : row3right
 * argv[16] : row4right
*/
#ifndef __RUSH_01__
	#define __RUSH_01__
	#include <unistd.h>
	#include <stdlib.h>
	#define __ERROR__ write(1, "Error\n", 6)
	int		is_valid_args(int argc, char **argv);
	int		**initialize_map(int argc, char **argv, unsigned int size);
	int		find_solution(int **map, int size);
	void	print_map(int **map, int size);
	void	finalize_map(int **map, int size);
#endif

int	main(int argc, char **argv)
{
	int	size;
	int	**map;

	if (!is_valid_args(argc,argv))
	{
		__ERROR__;
		return (0);
	}

	size = (argc - 1) / 4;

	map = initialize_map(argc, argv, size);

	if (find_solution(map, size))
		print_map(map, size);
	else
	 	__ERROR__;

	finalize_map(map, size);

	return (0);
}

int		is_valid_args(int argc, char **argv)
{
	if ( (argc - 1) >= 16 && (argc - 1) % 4 != 0)
		return (0);
	return (1);
}
