/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:47:32 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 23:04:34 by yoshin           ###   ########.fr       */
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
	free(pargv);
	return (0);
}
