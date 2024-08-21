/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:25:48 by subjeong          #+#    #+#             */
/*   Updated: 2024/08/21 19:45:36 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*parse_args(char *argv, unsigned int size)
{
	unsigned int	n;
	char			*pargv;

	pargv = (char *)malloc(sizeof(char) * (size * 4));
	n = -1;
	while (++n < size * 4)
		pargv[n] = argv[n * 2];
	return (pargv);
}
