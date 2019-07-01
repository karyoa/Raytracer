/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillcam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:46:05 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:46:07 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			fillcampos(t_cam *cam, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tCAM POS X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->origin.x, fd);
	ft_putstr_fd("\n\tCAM POS Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->origin.y, fd);
	ft_putstr_fd("\n\tCAM POS Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->origin.z, fd);
	ft_putendl_fd("", fd);
}

void			fillcamrot(t_cam *cam, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tCAM ROTATION W\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->rotate_start.w, fd);
	ft_putstr_fd("\n\tCAM ROTATION X\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->rotate_start.x, fd);
	ft_putstr_fd("\n\tCAM ROTATION Y\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->rotate_start.y, fd);
	ft_putstr_fd("\n\tCAM ROTATION Z\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->rotate_start.z, fd);
	ft_putendl_fd("", fd);
}

void			fillcamfin(t_cam *cam, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tCAM ALPHA\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->alpha, fd);
	ft_putstr_fd("\n\tCAM FOV\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)cam->fov, fd);
	ft_putendl_fd("", fd);
}
