/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:47:32 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 20:21:49 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	unsigned int	size;
	unsigned int	**map;
	char			*pargv;

	size = (unsigned int)is_valid_args(argc, argv);
	if (!size)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pargv = parse_args(argv[1], size);
	map = initialize_map(pargv, size);
	if (find_solution(map, size))
	{
		print_map(map, size);
	}
	else
		write(1, "Error\n", 6);
	finalize_map(map, size);
	return (0);
}

// =========================

// #include "main.h"
// #include "map.h"
// 
// int	main(int argc, char **argv)
// {
// 	unsigned int	size;
// 	unsigned int	**map;
// 
// 	if (!is_valid_args(argc, argv))
// 	{
// 		write(1, "Error\n", 6);
// 		return (0);
// 	}
// 	size = (argc - 1) / 4;
// 	map = initialize_map(argv, size);
// 	if (find_solution(map, size))
// 	{
// 		print_map(map, size);
// 		print_all_map(map, size);
// 	}
// 	else
// 		write(1, "Error\n", 6);
// 	finalize_map(map, size);
// 	return (0);
// }
