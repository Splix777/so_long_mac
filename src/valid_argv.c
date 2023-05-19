/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:04 by fsalazar          #+#    #+#             */
/*   Updated: 2023/05/17 13:37:00 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_argv(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (0);
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b'
		&& file[i - 4] == '.')
		return (1);
	ft_printf("Error: Invalid File Extension, use .ber file!\n");
	return (0);
}
