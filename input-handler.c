/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:05 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/06 18:54:26 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	height_count(char *file_name)
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

static int	width_count(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		i++;
	return (i);
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

static void	fill_int_line(char *line, t_map *map, int **coordinates_line)
{
	int			i;
	char		**temp;
	int			n;
	t_point		*p;

	if (!line)
		return ;
	temp = ft_split(line, ' ');
	map->size.width = width_count(temp);
	free(line);
	line = NULL;
	*coordinates_line = (int *)ft_calloc(map->size.width, sizeof (int));
	i = 0;
	while (i < map->size.width)
	{
		n = ft_atoi(temp[i]);
		(*coordinates_line)[i] = n;
		i++;
	}
	destroy_matrix((void **)temp);
}

int	coordinate_map(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->size.height = height_count(file_name);
	map->coordinates = (int **)ft_calloc(map->size.height + 1, sizeof (int *));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < map->size.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_int_line(line, map, &(map->coordinates[i]));
		i++;
	}
	get_next_line(fd);
}
