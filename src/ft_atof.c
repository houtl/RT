/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:13:39 by thou              #+#    #+#             */
/*   Updated: 2017/05/22 10:46:05 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_size(const char *nb)
{
	int				i;

	i = 0;
	while (nb[i] != '\0' && 1 == ft_isdigit(nb[i]))
		i += 1;
	return (i);
}

static double	get_integer_part(const char *nb, int *i)
{
	int				exp;
	int				size;
	double			result;

	result = 0;
	exp = 1;
	size = nb_size(&nb[*i]);
	while (1 < size)
	{
		exp *= 10;
		size -= 1;
	}
	while (nb[*i] != '\0' && 1 == ft_isdigit(nb[*i]))
	{
		result += (nb[*i] - '0') * exp;
		exp /= 10;
		*i += 1;
	}
	if (nb[*i] == '.')
		*i += 1;
	return (result);
}

static double	get_float_part(int neg, double result, const char *nb, int *i)
{
	int				exp;

	exp = 10;
	while (nb[*i] != '\0' && 1 == ft_isdigit(nb[*i]))
	{
		result += (double)(nb[*i] - '0') / exp;
		exp *= 10;
		*i += 1;
	}
	if (neg == 1)
		result = -result;
	return (result);
}

double			ft_atof(const char *nb, int *i)
{
	int				neg;
	double			result;

	while (1 == ft_iswhitespace(nb[*i]))
		*i += 1;
	if (nb[*i] == '-')
	{
		*i += 1;
		neg = 1;
	}
	else
		neg = 0;
	result = get_integer_part(nb, i);
	result = get_float_part(neg, result, nb, i);
	return (result);
}
