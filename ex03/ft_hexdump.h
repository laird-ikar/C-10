/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:31:38 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 16:38:06 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>

# ifndef POUBELLE
#  define POUBELLE

typedef struct s_variables
{
	int		i;
	int		j;
	int		n;
	int		m;
	int		fd;
	int		star;
	int		addr;
	char	buffer[16];
	char	*prev_b;
}	t_variables;

# endif

void	print_hexa(int addr, int i);
void	print_hexa_content(char c);
void	print_read_content(char c);
void	while_hexa(t_variables *all, int step);
void	put_data(t_variables *all);
void	buffer(t_variables *all);
void	put_rep(t_variables *all);
void	puterr(t_variables *all);

#endif
