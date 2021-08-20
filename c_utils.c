/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:09:15 by abambi            #+#    #+#             */
/*   Updated: 2021/07/08 20:50:17 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(int n)
{
	char	i;

	if (n < 0)
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			ft_putnbr(-n);
		}
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		i = n + '0';
		write(1, &i, 1);
	}
	return (1);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ch = (unsigned char)c;
	ptr = dest;
	while (len-- > 0)
	{
		*ptr = ch;
		ptr++;
	}
	return (dest);
}

int	ft_atoi(const char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' \
	|| *s == '\v' || *s == '\r' || *s == '\f')
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		num = num * 10;
		num = num + *s - 48;
		s++;
	}
	return (num * sign);
}
