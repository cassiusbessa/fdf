/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:05 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/26 20:26:31 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	line_count(char *file_name)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

void	destroy_matrix(void **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	fill_int_line(char *line, int *coordinates_line, int size)
{
	int			i;
	char		**temp;
	t_int_valid	n;

	if (!line)
		return ;
	temp = ft_split(line, ' ');
	free(line);
	line = NULL;
	i = 0;
	while (i < size)
	{
		n = ft_atoi(temp[i]);
		if (n.err)
			ft_printf("você está trollando o mapa");
		coordinates_line[i] = n.value;
		i++;
	}
	destroy_matrix((void **)temp);
}

int	map3d_generator(char *file_name)
{
	int		fd;
	int		**coordinates;
	int		line_size;
	char	*line;
	int		i;

	line_size = line_count(file_name);
	coordinates = (int **)ft_calloc(line_size + 1, sizeof (int *));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < line_size)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		coordinates[i] = (int *)ft_calloc(line_size + 1, sizeof (int));
		fill_int_line(line, coordinates[i], line_size);
		i++;
	}
	get_next_line(fd);
	destroy_matrix((void **)coordinates);
}
