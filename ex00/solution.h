/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:51 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:49:38 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SOLUTION_H
# define  SOLUTION_H
# include "pre_fill.h"
# include "validation_row.h"
# include "validation_col.h"
# include "utils.h"

int		recursive(
			unsigned int **map,
			unsigned int size,
			unsigned int f_count);
int		find_solution(unsigned int **map, unsigned int size);
#endif
