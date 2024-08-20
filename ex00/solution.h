/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:51 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 20:40:49 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SOLUTION_H
# define  SOLUTION_H
# include "validation.h"

int	__recursive__(
		unsigned int **map,
		unsigned int size,
		unsigned int f_count);
int	find_solution(unsigned int **map, unsigned int size);
#endif
