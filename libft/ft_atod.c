/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <mbeckert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 04:24:12 by mbeckert          #+#    #+#             */
/*   Updated: 2017/08/24 00:24:14 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	double	d;
	int		i;
	char	c;

	c = str[0];
	d = ft_atoi(str);
	str = ft_strchr(str, '.');
	if (str)
	{
		str++;
		i = 0;
		while (str[i])
		{
			if (c == '-')
				d -= (double)(str[i] - 48) * 1.0 / (double)ft_pow(10, i + 1);
			else
				d += (double)(str[i] - 48) * 1.0 / (double)ft_pow(10, i + 1);
			i++;
		}
	}
	return (d);
}
