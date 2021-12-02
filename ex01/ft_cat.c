/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:55:11 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 15:00:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2 || argv[1][0] == '-')
		ft_read_input();
	else
	{
		i = 1;
		while (argv[i])
		{
			ft_read_files(argv[i]);
			i++;
		}
	}
}

void	ft_read_files(char *file)
{
	int		fd;
	char	buffer;
	char	*err;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		err = strerror(errno);
		write(1, err, ft_strlen(err));
		write(1, "\n", 1);
	}
	else
	{
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
	close(fd);
}

void	ft_read_input(void)
{
	char	buffer;

	while (read(0, &buffer, 1))
		write(1, &buffer, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
