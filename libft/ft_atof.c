/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:46:22 by arguerin          #+#    #+#             */
/*   Updated: 2018/07/24 21:47:08 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	nb;
	double	nb2;
	char	*c;
	int		len;

	c = (char *)str;
	nb = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	nb2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		nb2 /= 10;
	return (nb + ((nb > 0) ? nb2 : -nb2));
}
