/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:25:05 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/04 16:21:15 by caqueiro         ###   ########.fr       */
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

static void	fill_int_line(char *line, int **coordinates_line)
{
	int			i;
	char		**temp;
	int			width;
	t_int_valid	n;

	if (!line)
		return ;
	temp = ft_split(line, ' ');
	width = width_count(temp);
	free(line);
	line = NULL;
	*coordinates_line = (int *)ft_calloc(width, sizeof (int));
	i = 0;
	while (i < width)
	{
		n = ft_atoi(temp[i]);
		if (n.err)
			ft_printf("você está trollando o mapa\n");
		(*coordinates_line)[i] = n.value;
		i++;
	}
	destroy_matrix((void **)temp);
}

int	map3d_generator(char *file_name)
{
	int		fd;
	int		**coordinates;
	int		heigth;
	char	*line;
	int		i;

	heigth = height_count(file_name);
	coordinates = (int **)ft_calloc(heigth + 1, sizeof (int *));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < heigth)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//coordinates[i] = (int *)ft_calloc(19, sizeof (int));
		fill_int_line(line, &(coordinates[i]));
		i++;
	}
	get_next_line(fd);
	destroy_matrix((void **)coordinates);
}
