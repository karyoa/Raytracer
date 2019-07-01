/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillscn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:03:51 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 02:08:51 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			filltype(t_object *object, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	fchmod(fd, S_IWUSR | S_IWGRP | S_IWOTH | S_IRUSR | S_IRGRP | S_IROTH);
	if (object->type == 0)
		ft_putendl_fd("\nPLANE", fd);
	if (object->type == 1)
		ft_putendl_fd("\nSPHERE", fd);
	if (object->type == 2)
		ft_putendl_fd("\nCYLINDER", fd);
	if (object->type == 3)
		ft_putendl_fd("\nCONE", fd);
	if (object->type == 4)
		ft_putendl_fd("\nDISK", fd);
}

void			fillpos(t_object *object, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tX\t\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->pos.x, fd);
	ft_putstr_fd("\n\tY\t\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->pos.y, fd);
	ft_putstr_fd("\n\tZ\t\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->pos.z, fd);
	ft_putstr_fd("\n\tRotate X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->rotate.rot.x, fd);
	ft_putstr_fd("\n\tRotate Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->rotate.rot.y, fd);
	ft_putstr_fd("\n\tRotate Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->rotate.rot.z, fd);
	ft_putendl_fd("", fd);
}

void			fillcol(t_object *object, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tRED\t\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->color.x, fd);
	ft_putstr_fd("\n\tGREEN\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->color.y, fd);
	ft_putstr_fd("\n\tBLUE\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->color.z, fd);
	ft_putendl_fd("", fd);
}

void			fillcolt(t_object *object, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tRED_T\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->color_t.x, fd);
	ft_putstr_fd("\n\tGREEN_T\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->color_t.y, fd);
	ft_putstr_fd("\n\tBLUE_T\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->color_t.z, fd);
	ft_putstr_fd("\n\tName\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putendl_fd(object->name, fd);
}

void			fillrefl(t_object *object, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tdiffuse_refl\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->diffuse_refl, fd);
	ft_putstr_fd("\n\tspecular_refl\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->specular_refl, fd);
	ft_putstr_fd("\n\tspecular_refr\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->specular_refr, fd);
	ft_putstr_fd("\n\tdiffuse_refr\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->diffuse_refr, fd);
	ft_putstr_fd("\n\tdiffuse_ambt\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->diffuse_ambt, fd);
	ft_putstr_fd("\n\tshininess\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->shininess, fd);
	ft_putendl_fd("", fd);
}
