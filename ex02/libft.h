/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdehais <bdehais@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:56:39 by bdehais           #+#    #+#             */
/*   Updated: 2021/11/25 15:33:06 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_swap(int *a, int *b);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
int		ft_recursive_power(int nb, int power);
int		ft_recursive_factorial(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

# endif
