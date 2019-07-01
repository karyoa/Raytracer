/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 01:17:34 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 01:17:36 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			setlabelposition(t_label *lab, int x, int y)
{
	lab->p.x = x;
	lab->p.y = y;
}

void			deletelabel(t_label *lab)
{
	SDL_FreeSurface(lab->text);
	ft_strdel(&(lab->val));
	ft_strdel(&(lab->key));
	ft_memdel((void**)(&lab));
}

void			setlabeltext(t_label *lab, char *text, t_itf *interface)
{
	SDL_Color	col;

	col.r = 255;
	col.g = 255;
	col.b = 255;
	ft_strdel(&(lab->val));
	lab->val = ft_strdup(text);
	lab->text = TTF_RenderText_Solid(interface->font, lab->val, col);
}

void			displaylabelcmi(t_itf *interface, int i)
{
	SDL_Rect	r;

	r.x = interface->currentmenu->label[i]->p.x + 8;
	r.y = interface->currentmenu->label[i]->p.y + 8;
	SDL_BlitSurface(interface->currentmenu->label[i]->text, NULL,
			interface->result, &r);
}

void			addlabel(t_itf *interface, char *key, t_label *label)
{
	t_menu		*menu;

	menu = getmenu(interface, key);
	menu->label = (t_label**)ft_pushback(menu->label, menu->nblabel,
			sizeof(t_label*));
	menu->label[menu->nblabel] = label;
	menu->nblabel++;
}
