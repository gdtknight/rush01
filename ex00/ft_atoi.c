/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:38:30 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 16:27:48 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_atoi(char *str)
{
	int	flag;
	int	result;

	result = 0;
	flag = 0;
	while (__is_space__(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = !flag;
		str++;
	}
	while (__is_numeric__(*str))
	{
		result *= 10;
		result += (*str++ - '0');
	}
	if (flag)
		result *= (-1);
	return (result);
}

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
int	__is_space__(char c)
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

int	__is_numeric__(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
