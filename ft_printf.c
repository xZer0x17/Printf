/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alflores <alflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:04:19 by alflores          #+#    #+#             */
/*   Updated: 2023/01/16 19:46:51 by alflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//Para printear:
int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}
//Para el tamaño del string:
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
//Para printear el string de forma "tradicional"
int ft_printf_string(char const *str)
{
	return(write(1, str, ft_strlen(str)));
}
//Para comprobar si es negativo:
static int	ft_negnb(int nb)
{
	if (nb < 0)
		return (-nb);
	return nb;
}
//Para ver el tamaño del número entero:
static	int ft_nblen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = ft_negnb(nb);
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len ++;
	}
	return len;
}
//Para printear el numero decimal en base 10
int	ft_printf_d(int nb)
{
	char	*str;
	int		n;
	int		i;
	int		aux;

	n = ft_negnb(nb);
	i = ft_nblen(nb);
	aux = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	while (i >= 0)
	{
		if (nb < 0 && i == 0)
			str[i--] = '-';
		else
		{
			str[i--] = (nb % 10) + '0';
			nb = nb / 10;
		}
	}
	return(write(1,str,aux));
}

void ft_distributioner(char const format, va_list argv)
{
	if (format == 'c')
		ft_putchar(va_arg(argv, int));
	else if (format == 's')
		ft_printf_string(va_arg(argv, char const *));
	else if (format == 'd')
		ft_printf_d(va_arg(argv, int));
}

int	ft_printf(char const *format, ...)
{
	int i;
	char	*aux;
	va_list	argv;//en esta lista voy a ir guardando los argumentos de las variables
	
	i = 0;
	aux =(char *) format;
	va_start(argv, format);
	while(*aux)
	{
		if (*aux == '%')
		{
			aux++;
			ft_distributioner(*aux, argv);
			i++;
		}
		else
			ft_putchar(*aux);
			i++;
		aux++;
	}
	va_end(argv);
	return i;
}


int main()
{
	int	a;
	int	b;
	int c;
	char	*str;
	
	str = "Hola"; 
	c = -2223;	
	a = 83;
	b = 80;
	ft_printf("La primera letra de mi nommbre es:%c y la ultima es %c y la palabra es %s y el num es %d", a, b, str, c);
}