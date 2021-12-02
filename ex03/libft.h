/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:31:45 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/02 08:33:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

char	*ft_strstr(char *str, char *to_find);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(char *src);
char	*ft_strdup(char *src);

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_recursive_power(int nb, int power);
int		ft_recursive_factorial(int nb);
int		ft_atoi(char *str);

#endif
