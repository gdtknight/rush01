/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 22:49:55 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H
# include "utils.h"
# include "ft_atoi.h"

int	is_valid_args(int argc, char **argv);
int	is_valid_map(unsigned int **map, unsigned int size);
int	is_valid_row(unsigned int **map, unsigned int size, unsigned int row);
int	is_valid_col(unsigned int **map, unsigned int size, unsigned int col);
#endif
