/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:28:15 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 20:54:12 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_atoi.h"

unsigned int	**initialize_map(char **argv, unsigned int size);
void			fill_map(unsigned int **map, unsigned int size, char **argv);
void			finalize_map(unsigned int **map, unsigned int size);
void			print_map(unsigned int **map, unsigned int size);
#endif
