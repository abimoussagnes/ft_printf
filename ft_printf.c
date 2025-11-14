/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabi-mou <aabi-mou@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:06:33 by aabi-mou          #+#    #+#             */
/*   Updated: 2025/11/14 11:17:59 by aabi-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		i = 6;
	}
	else
	{
		while (i < ft_strlen(s))
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	return (i);
}
static int	put_hex(unsigned long n, char c)
{
	const char	*base1 = "0123456789abcdef";
	const char	*base2 = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (c == 'x')
	{
		if (n >= 16)
			count += put_hex(n / 16, c);
		else
		{
			ft_putchar(base1[n % 16]);
			count++;
		}
	}
	else if (c == 'X')
	{
		if (n >= 16)
			count += put_hex(n / 16, c);
		else
		{
			ft_putchar(base2[n % 16]);
			count++;
		}
	}
	return (count);
}

static int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		count++;
	}
	return (count);
}

static int	ft_specifier_check(char c, va_list args)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	if (c == 'c')
	{
		len = ft_putchar((char)va_arg(args, int));
	}
	else if (c == 's')
	{
		len = put_str(va_arg(args, char *));
	}
	else if (c == 'p')
	{
		// len = put_hex((unsigned long)va_arg(args, void *));
	}
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr(va_arg(args, int));
	}
	else if (c == 'u')
	{
		ft_putnbr((unsigned int)va_arg(args, int));
	}
	else if (c == 'x' || c == 'X')
	{
		len = ft_puthex(va_arg(args, unsigned long), c);
	}
	else if (c == '%')
	{
		len = ft_putchar(c);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_specifier_check(str[i], args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
