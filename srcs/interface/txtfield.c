/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtfield.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 01:45:59 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 01:46:01 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_tf			*createtextfield(char *key)
{
	t_tf		*tfd;

	if (!(tfd = (t_tf*)ft_memalloc(sizeof(t_tf))))
		return (NULL);
	tfd->key = ft_strdup(key);
	tfd->p.h = 35;
	tfd->val = ft_strnew(0);
	return (tfd);
}

void			appendcmactivetextfield(char *text, t_itf *interface)
{
	int			i;

	i = 0;
	while (i < interface->currentmenu->nbtextfield)
	{
		if (interface->currentmenu->tf[i]->isactive)
			appendcmitextfield(i, text, interface);
		i++;
	}
}

void			addtextfield(t_itf *interface, char *key, t_tf *tf)
{
	t_menu		*menu;

	menu = getmenu(interface, key);
	menu->tf = (t_tf**)ft_pushback(menu->tf,
			menu->nbtextfield, sizeof(t_tf*));
	menu->tf[menu->nbtextfield] = tf;
	menu->nbtextfield++;
}

void			settextfieldposition(t_tf *tfd, int x, int y, int w)
{
	tfd->p.x = x;
	tfd->p.y = y;
	tfd->p.w = w;
}
