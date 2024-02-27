/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:06:22 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/22 16:52:34 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	n_validator(long long n)
{
	return (n <= 2147483647 && n >= -2147483648);
}

static t_int_valid	atoi_error(void)
{
	t_int_valid	err;

	err.err = 1;
	err.value = 0;
	return (err);
}

t_int_valid	ft_atoi(const char *nptr)
{
	int			i;
	t_int_valid	n;
	int			minus;

	i = 0;
	n.value = 0;
	n.err = 0;
	minus = 1;
	if (nptr[i] == '-')
	{
		minus = minus * -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]) && !nptr[i])
		return (n.err = 1, n);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i])
			|| !n_validator((long long)n.value * 10 + (nptr[i] - '0') * minus))
			return (atoi_error());
		n.value = n.value * 10 + (nptr[i] - '0');
		i++;
	}
	n.value = n.value * minus;
	return (n);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	printf("%d", ft_atoi("	  1234ab567") == atoi("	  1234ab567"));
}*/
