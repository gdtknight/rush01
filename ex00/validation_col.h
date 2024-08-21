/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_col.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:03:39 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_COL_H
# define VALIDATION_COL_H
# include "utils.h"
# include "ft_atoi.h"

int	is_valid_col(unsigned int **map, unsigned int size, unsigned int col);
int	is_unique_col(unsigned int **map, unsigned int size, unsigned int col);
int	is_valid_colup(unsigned int **map, unsigned int size, unsigned int col);
int	is_valid_coldown(unsigned int **map, unsigned int size, unsigned int col);
#endif
