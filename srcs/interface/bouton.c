/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:40:44 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 00:40:46 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			addbutton(t_itf *interface, char *key, t_button *but)
{
	t_menu		*menu;

	menu = getmenu(interface, key);
	menu->but = (t_button**)ft_pushback(menu->but,
			menu->nbbutton, sizeof(t_button*));
	menu->but[menu->nbbutton] = but;
	menu->nbbutton++;
}

t_button		*createbutton(char *key)
{
	t_button	*but;

	if (!(but = (t_button*)ft_memalloc(sizeof(t_button))))
		return (NULL);
	ft_bzero((void*)but, sizeof(t_button));
	but->key = ft_strdup(key);
	return (but);
}

t_button		*crmenubutton(t_itf *interface, char *mkey, char *bkey)
{
	t_button	*but;

	but = NULL;
	but = createbutton(bkey);
	if (but)
		addbutton(interface, mkey, but);
	return (but);
}

void			setbuttonposition(t_button *but, int x, int y)
{
	but->p.x = x;
	but->p.y = y;
}

void			setbuttontext(t_button *but, char *text, t_itf *interface)
{
	SDL_Rect	r;
	SDL_Color	col;

	col.r = 255;
	col.g = 255;
	col.b = 255;
	but->val = ft_strdup(text);
	but->text = TTF_RenderText_Solid(interface->font, but->val, col);
	SDL_GetClipRect(but->text, &r);
	but->p.w = r.w + 16;
	but->p.h = r.h + 16;
}
