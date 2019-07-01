/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:48:02 by mbeckert          #+#    #+#             */
/*   Updated: 2016/11/28 12:20:16 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pushback(void *tab, int size_tab, int size_type)
{
	void	*newtab;

	newtab = NULL;
	if ((newtab = ft_memalloc(size_type * (size_tab + 1))))
		newtab = ft_memcpy(newtab, tab, size_type * size_tab);
	ft_memdel(&tab);
	return (newtab);
}
