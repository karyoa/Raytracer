/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:31:37 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 00:54:38 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			deletebutton(t_button *but)
{
	SDL_FreeSurface(but->text);
	ft_strdel(&(but->val));
	ft_strdel(&(but->key));
	ft_memdel((void**)(&but));
}

void			setbuttonfunction(t_button *but, void (*f)())
{
	but->f = f;
}

void			displaybuttoncmi(t_itf *interface, int i)
{
	SDL_Rect	r;

	SDL_BlitSurface(interface->img, &(interface->currentmenu->but[i]->p),
			interface->result, &(interface->currentmenu->but[i]->p));
	SDL_BlitSurface(interface->currentmenu->but[i]->isactive ?
			interface->hov_but : interface->rel_but,
			&(interface->currentmenu->but[i]->p), interface->result,
			&(interface->currentmenu->but[i]->p));
	r.x = interface->currentmenu->but[i]->p.x + 8;
	r.y = interface->currentmenu->but[i]->p.y + 8;
	SDL_BlitSurface(interface->currentmenu->but[i]->text, NULL,
			interface->result, &r);
}

void			setbuttondefaultmenu(t_button *but, char *key)
{
	but->dftmenu = ft_strdup(key);
}

t_button		*getmenubutton(t_itf *interface, char *mkey, char *bkey)
{
	t_menu		*menu;
	int			i;

	menu = NULL;
	menu = getmenu(interface, mkey);
	if (!menu)
		return (NULL);
	i = 0;
	while (i < menu->nbbutton)
	{
		if (!ft_strcmp(menu->but[i]->key, bkey))
			return (menu->but[i]);
		i++;
	}
	return (NULL);
}
