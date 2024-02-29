/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin-wu-helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:55:25 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/29 20:45:57 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	calculate_steep(t_point *p0, t_point *p1)
{
	int	steep;

	steep = (absolute(p1->y - p0->y) > absolute(p1->x - p0->x));
	if (steep)
	{
		swap(&((*p0).x), &((*p0).y));
		swap(&((*p1).x), &((*p1).y));
	}
	if (p0->x > p1->x)
	{
		swap(&(*p0).x, &((*p1).x));
		swap(&((*p0).y), &((*p1).y));
	}
	return (steep);
}
