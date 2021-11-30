/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:56:03 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/30 10:56:04 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tail.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	file_size;

	if (argc < 4)
		ft_read_input(ft_atoi(argv[2]));
	else if (argc == 4)
	{
		file_size = ft_count_file_size(argv[3]);
		ft_read_files(argv[3], file_size, ft_atoi(argv[2]));
	}
	else
	{
		i = 3;
		while (argv[i])
		{
			file_size = ft_count_file_size(argv[i]);
			write(1, "==> ", 4);
			write(1, argv[i], file_size + 1);
			write(1, " <==\n", 5);
			ft_read_files(argv[3], file_size, ft_atoi(argv[2]));
			if (argv[i + 1])
				write(1, "\n", 2);
			i++;
		}
	}
}

void	ft_read_files(char *file, int file_size, int n)
{
	int		fd;
	int		i;
	char	buffer;
	char	*err;

	i = 0;
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
		{
			if (i >= file_size - n - 1)
				write(1, &buffer, 1);
			i++;
		}
	}
	close(fd);
}

int	ft_count_file_size(char *file)
{
	int		fd;
	int		i;
	char	buffer;
	char	*err;

	i = 0;
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
			i++;
	}
	close(fd);
	return (i + 1);
}

void	ft_read_input(int n)
{
	char	buffer;
	char	*tab;
	int		size;
	int		i;

	size = 0;
	i = 0;
	write(1, "read_input\n", 11);
	while (read(0, &buffer, 1))
		size++;
	tab = malloc(sizeof(char) * size + 1);
	while (read(0, &buffer, 1))
	{
		tab[i] = buffer;
		i++;
	}
	i = 0;
	while (read(0, &buffer, 1))
	{
		if (i >= size - n - 1)
			write(1, &(tab[i]), 1);
		i++;
	}
}
