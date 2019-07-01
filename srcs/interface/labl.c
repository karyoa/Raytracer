/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 01:23:46 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 01:23:48 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_label			*createlabel(char *key)
{
	t_label		*lab;

	if (!(lab = (t_label*)ft_memalloc(sizeof(t_label))))
		return (NULL);
	ft_bzero((void*)lab, sizeof(t_label));
	lab->key = ft_strdup(key);
	return (lab);
}

t_label			*createmenulabel(t_itf *interface, char *mkey, char *lkey)
{
	t_label		*lab;

	lab = NULL;
	lab = createlabel(lkey);
	if (lab)
		addlabel(interface, mkey, lab);
	return (lab);
}
