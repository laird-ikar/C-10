/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 16:36:43 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include "poubelle.h"
#include "libft.h"

char	g_hex_base[16] = "0123456789abcdef";

int	main(int argc, char *argv[])
{
	t_variables	all;

	(void) argc;
	all.i = 1;
	all.addr = 0;
	all.prev_b = malloc(sizeof(char) * 16);
	while (argv[++all.i])
	{
		all.fd = open(argv[all.i], O_RDONLY);
		puterr(&all);
		if (all.fd >= 0)
		{
			all.addr = 0;
			all.n = read(all.fd, all.buffer, 16);
			while (all.n)
			{
				buffer(&all);
			}
			print_hexa(all.addr + all.m, 8);
			close(all.fd);
		}
	}
	ft_putstr("\n");
	free(all.prev_b);
}

void	print_hexa(int c, int n)
{
	if (n > 1)
		print_hexa(c / 16, n - 1);
	write(1, &g_hex_base[c % 16], 1);
}

void	print_read_content(char c)
{
	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		ft_putstr(".");
}

void	while_hexa(t_variables *all, int step)
{
	while (all->j < step)
	{
		if (all->j < all->n)
			print_hexa((unsigned char) all->buffer[all->j], 2);
		else
			ft_putstr("  ");
		ft_putstr(" ");
		all->j++;
	}
}

void	put_data(t_variables *all)
{
	all->star = 0;
	print_hexa(all->addr, 8);
	ft_putstr("  ");
	all->j = 0;
	while_hexa(all, 8);
	ft_putstr(" ");
	while_hexa(all, 16);
	ft_putstr(" ");
	all->j = 0;
	ft_putstr("|");
	while (all->j < all->n)
		print_read_content(all->buffer[all->j++]);
	ft_putstr("|");
	free(all->prev_b);
	all->prev_b = ft_strdup(all->buffer);
	ft_putstr("\n");
}
