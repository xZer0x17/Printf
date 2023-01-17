/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alflores <alflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:04:19 by alflores          #+#    #+#             */
/*   Updated: 2023/01/18 00:11:40 by alflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//Desde donde se distribuye todo:
static int	ft_distributor_num(int num, char format)
{
	char	*base_hex_min;
	char	*base_hex_upp;
	char	*base_dec;

	base_hex_min = "0123456789abcdef";
	base_hex_upp = "0123456789ABCDEF";
	base_dec = "0123456789";
	if (format == 'd' || format == 'i') //Para las condiciones donde los ints son los mismos:
	{
		if (num == -2147483648)//Tamañano máximo del int
			return (write(1, "-2147483648", 11));
		else if (num < 0)
			return (ft_putchar('-') + ft_base(num * -1, base_dec));
		else
			return (ft_base(num, base_dec));
	}
	else if (format == 'u')
		return (ft_base((unsigned int)num, base_dec));
	else if (format == 'x')
		return (ft_base((unsigned int)num, base_hex_min));
	else if (format == 'X')
		return (ft_base((unsigned int)num, base_hex_upp));
}

static int	ft_main_distributor(char const *format, va_list argv)
{
	if (*format == '%')
		return (ft_putchar('%'));
	else if (*format == 'c')
		return (ft_putchar(va_arg(argv, int)));
	else if (*format == 's')
		return (ft_printf_string(va_arg(argv, char const *)));
	else if (*format == 'p')
		return (ft_print_ptr(va_arg(argv, void *)));
	else
		return (ft_distributor_num(va_arg(argv, int), *format));
}

int	ft_printf(char const *format, ...)
{
	int i;
	char	*aux;
	va_list	argv;

	i = 0;
	aux =(char *) format;
	va_start(argv, format);
	while(*aux)
	{
		if (*aux == '%')
		{
			aux++;
			if (ft_error(*aux))
				i += ft_main_distributor(*aux, argv);
			else
				return (-1);
		}
		else
		{
			ft_putchar(*aux);
			i++;
		}
		aux++;
	}
	va_end(argv);
	return (i);
}

/* //Main pruebitas
int main()
{
	int	a;
	int	b;
	int c;
	int	d;
	int e;
	char	*str;
	
	str = "Hola"; 
	c = -10000;	
	a = 83;
	b = 80;
	d = -1723;
	e = -1;
	ft_printf("La primera letra de \n mi nommbre es: y la ultima es y la palabra es y el num es %d, y en hexa es: %x y el unsigned es %u", c, d, e);
} */