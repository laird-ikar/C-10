/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 11:17:11 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include "libft.h"

char g_hex_base[16] = "0123456789abcdef";

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		n;
	int		m;
	int		fd;
	int		star;
	int		addr;
	char	*err;
	char	buffer[16];
	char	*prev_b;

	i = 1;
	addr = 0;
	prev_b = malloc(sizeof(char) * 16);
	while (argv[argc - argc + (++i)])
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			err = strerror(errno);
			write(2, err, ft_strlen(err));
		}
		else
		{
			addr = 0;
			n = read(fd, buffer, 16);
			while (n)
			{
					if (!ft_strcmp(buffer, prev_b))
					{
						if (!star)
						{
							star = 1;
							write(1, "*\n", 2);
						}
					}
					else
					{
						star = 0;
						print_hexa(addr, 8);
						ft_putstr("  ");
						j = 0;
						while (j < 8)
						{
							if (j < n)
								print_hexa((unsigned char) buffer[j], 2);
							else
								ft_putstr("  ");
							ft_putstr(" ");
							j++;
						}
						ft_putstr(" ");
						while (j < 16)
						{
							if (j < n)
								print_hexa((unsigned char) buffer[j], 2);
							else
								ft_putstr("  ");
							ft_putstr(" ");
							j++;
						}
						ft_putstr(" ");
						j = 0;
						ft_putstr("|");
						while (j < n)
							print_read_content(buffer[j++]);
						ft_putstr("|");
						free(prev_b);
						prev_b = ft_strdup(buffer);
						ft_putstr("\n");
					}
				n = read(fd, buffer, 16);
				if (n)
				{
					m = n;
					addr += 16;
				}
			}
			print_hexa(addr + m, 8);
			close(fd);
		}
	}
	ft_putstr("\n");
	free(prev_b);
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
