/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:13:32 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 20:14:37 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_args.h"

int	is_valid_args(int argc, char *argv[])
{
	int	size;
	int	n;

	if (argc - 1 != 1)
		return (0);
	n = -1;
	while (argv[1][++n] != '\0')
	{
		if (n % 2 == 0 && \
		!((unsigned char)argv[1][n] >= '1' && \
		(unsigned char)argv[1][n] <= '9'))
			return (0);
		else if (n % 2 == 1 && (unsigned char)argv[1][n] != ' ')
			return (0);
	}
	size = 3;
	while (++size < 10)
	{
		if ((n + 1) / 2 == size * 4)
			return (size);
	}
	return (0);
}
