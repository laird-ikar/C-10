/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:33:26 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 16:39:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poubelle.h"
#include "libft.h"
#include "ft_hexdump.h"

void	puterr(t_variables *all)
{
	char	*err;

	if (all->fd < 0)
	{
		err = strerror(errno);
		write(2, err, ft_strlen(err));
	}
}

void	put_rep(t_variables *all)
{
	if (!ft_strcmp(all->buffer, all->prev_b))
	{
		if (!all->star)
		{
			all->star = 1;
			write(1, "*\n", 2);
		}
	}
}

void	buffer(t_variables *all)
{
	put_rep(all);
	if (ft_strcmp(all->buffer, all->prev_b))
	{
		put_data(all);
	}
	all->n = read(all->fd, all->buffer, 16);
	if (all->n)
	{
		all->m = all->n;
		all->addr += 16;
	}
}
