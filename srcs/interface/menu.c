/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 01:24:06 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 01:24:46 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_menu			*createmenu(char *key)
{
	t_menu		*menu;

	menu = (t_menu*)ft_memalloc(sizeof(t_menu));
	menu->key = key;
	menu->nbbutton = 0;
	menu->nbtextfield = 0;
	menu->nblabel = 0;
	return (menu);
}

void			deletemenu(t_menu *menu)
{
	while (menu->nbbutton > 0)
	{
		menu->nbbutton--;
		deletebutton(menu->but[menu->nbbutton]);
	}
	ft_memdel((void**)&(menu->but));
	ft_memdel((void**)&menu);
}

void			switchmenu(t_itf *interface, char *menu)
{
	int			i;

	interface->currentmenu = getmenu(interface, menu);
	SDL_BlitSurface(interface->img, NULL, interface->result, NULL);
	SDL_BlitSurface(interface->frame, &(interface->currentmenu->bg),
			interface->result, &(interface->currentmenu->bg));
	i = 0;
	while (i < interface->currentmenu->nbbutton)
	{
		displaybuttoncmi(interface, i);
		i++;
	}
	i = 0;
	while (i < interface->currentmenu->nbtextfield)
	{
		displaytextfieldcmi(interface, i);
		i++;
	}
	i = 0;
	while (i < interface->currentmenu->nblabel)
	{
		displaylabelcmi(interface, i);
		i++;
	}
}

void			addmenu(t_itf *interface, t_menu *menu)
{
	interface->menu = (t_menu**)ft_pushback(interface->menu, interface->nbmenu,
			sizeof(t_menu*));
	interface->menu[interface->nbmenu] = menu;
	interface->nbmenu++;
}

t_menu			*getmenu(t_itf *interface, char *key)
{
	int			i;

	i = 0;
	while (i < interface->nbmenu && ft_strcmp(key, interface->menu[i]->key))
		i++;
	if (i == interface->nbmenu)
		addmenu(interface, createmenu(key));
	return (interface->menu[i]);
}
