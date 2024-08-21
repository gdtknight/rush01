/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:47:56 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:49:22 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 * checks for white-space characters.
 * In the "C" and "POSIX" locales, these are
 *  - space
 *  - form-feed ('\f')
 *  - newline ('\n')
 *  - carriage return ('\r')
 *  - horizontal tab ('\t')
 *  - vertical tab ('\v').
 */
int	is_space(char c)
{
	if ((c == ' ')
		|| (c == '\f')
		|| (c == '\n')
		|| (c == '\r')
		|| (c == '\t')
		|| (c == '\v'))
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
