/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:56:03 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/01 15:05:14 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tail.h"

int	main(int argc, char *argv[])
{
	int		file_size;
	int		fd;
	char	buffer;

	if (argc < 4)
	{
		fd = open("temp", O_RDWR | O_TRUNC);
		while (read(0, &buffer, 1) && buffer != 13)
		{
			write(fd, &buffer, 1);
		}
		close(fd);
		file_size = ft_count_file_size("temp");
		ft_read_files("temp", file_size, ft_atoi(argv[2]));
	}
	else if (argc == 4)
	{
		file_size = ft_count_file_size(argv[3]);
		ft_read_files(argv[3], file_size, ft_atoi(argv[2]));
	}
	else
	{
		ft_read_mult(argv, &file_size);
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

void	ft_read_mult(char **strs, int *file_size)
{
	int	i;

	i = 3;
	while (strs[i])
	{
		*file_size = ft_count_file_size(strs[i]);
		write(1, "==> ", 4);
		write(1, strs[i], *file_size + 1);
		write(1, " <==\n", 5);
		ft_read_files(strs[3], *file_size, ft_atoi(strs[2]));
		if (strs[i + 1])
			write(1, "\n", 2);
		i++;
	}
}
