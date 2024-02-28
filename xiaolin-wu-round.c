/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin-wu-round.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:20:41 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/28 17:52:27 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absolute(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	int_part(float x)
{
	return ((int) x);
}

int	round_number(float x)
{
	return (int_part(x + 0.5));
}

float	float_part(float x)
{
	if (x > 0)
		return (x - int_part(x));
	else
		return (x - (int_part(x) + 1));
}

float	one_less_float_part(float x)
{
	return (1 - float_part(x));
}
