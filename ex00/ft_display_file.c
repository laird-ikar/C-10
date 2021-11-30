/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:54:58 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/30 10:55:00 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_puterr(char *err);

int	main(int argc, char *argv[])
{
	int		fd;
	char	buffer;

	if (argc < 2)
		ft_puterr("File name missing.\n");
	else if (argc > 2)
		ft_puterr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_puterr("Cannot read file.\n");
		else
		{
			while (read(fd, &buffer, 1))
			{
				write(1, &buffer, 1);
			}
		}
		close(fd);
	}
}

void	ft_puterr(char *err)
{
	int		i;

	i = 0;
	while (err[i])
	{
		write(2, &err[i], 1);
		i++;
	}
}
