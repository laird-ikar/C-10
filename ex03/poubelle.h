/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:33:53 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 16:37:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POUBELLE_H
# define POUBELLE_H

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

void	puterr(t_variables *all);
void	put_rep(t_variables *all);
void	buffer(t_variables *all);

#endif
