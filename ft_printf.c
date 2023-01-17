/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alflores <alflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:04:19 by alflores          #+#    #+#             */
/*   Updated: 2023/01/17 23:16:59 by alflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//Para printear el string de forma "tradicional"
// int ft_printf_string(char const *str)
// {
// 	return(write(1, str, ft_strlen(str)));
// }
//Para comprobar si es negativo:
// static int	ft_negnb(int nb)
// {
// 	if (nb < 0)
// 		return (-nb);
// 	return nb;
// }
//Para ver el tamaño del número entero:
// static	int ft_nblen(int nb)
// {
// 	int	len;

// 	len = 0;
// 	if (nb < 0)
// 		len++;
// 	while (nb !=  0)
// 	{
// 		nb /= 10;
// 		len ++;
// 	}
// 	return len;
// }
//Para printear el numero decimal en base 10
// int	ft_printf_d(int nb)
// {
// 	char	*str;
// 	int		i;
// 	int		n;
// 	int		aux;

// 	i = ft_nblen(nb);
// 	n = ft_negnb(nb);
// 	aux = i;
// 	str = (char *)malloc(sizeof(char) * (i + 1));
// 	str[i--] = '\0';
// 	while (i >= 0)
// 	{
// 		if (nb < 0 && i == 0)
// 			str[i--] = '-';
// 		else
// 		{
// 			str[i--] = (n % 10) + '0';
// 			n = n / 10;
// 		}
// 	}
// 	return(write(1,str,aux));
// }
//Para el tamaño del string:
/* size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
} */
//Para printear:
int	ft_putchar(char c)
{
	return(write(1, &c, 1));
} 
//Para los punteros:
static int	ft_pointer(size_t num)
{
	size_t	len;
	char	*base;

	len = 1;
	base = "0123456789abcdef";
	if (num >= (size_t)ft_strlen(base))
	{
		len += ft_pointer(num / ft_strlen(base));
		ft_putchar(base[num % ft_strlen(base)]);
	}
	else
		ft_putchar(base[num]);
	return (len);
}

static int	ft_print_ptr(void *ptr)
{
	size_t	ptr_num;
	int		len;

	len = 0;
	ptr_num = (size_t)ptr;//Necesito una función aparte para aplicar la recursividad sin que falle a la hora de contar los bites
	return (write(1, "0x", 2) + ft_pointer(ptr_num));
}
//Para el tema de las bases
static int	ft_base(size_t num, char *base)
{
	size_t	len;

	len = 1;
	if (num >= (size_t)ft_strlen(base))
	{
		len += ft_base(num / ft_strlen(base), base);//Regresiva para que el num se vaya haciendo más pequeño y poder tener en cuenta el num de bytes que va a ocupar
		ft_putchar(base[num % ft_strlen(base)]);//Para que vaya printeando el numero a la derecha
	}
	else
		ft_putchar(base[num]);//Para cuando es menor que la base y es simplemente ese número
	return (len);
}
//Desde donde se distribuyen los enteros:
int	ft_distributor_num(int num, char format)
{
	char	*base_hex_min;
	char	*base_hex_upp;
	char	*base_dec;

	base_hex_min = "0123456789abcdef";
	base_hex_upp = "0123456789ABCDEF";
	base_dec = "0123456789";
	if (format == 'd' || format == 'i') //Para las condiciones donde los ints son los mismos:
	{
		if (num == -2147483648)//Tamañano mínimo negativo del int
			return (write(1, "-2147483648", 11));
		else if (num < 0)
			return (ft_putchar('-') + ft_base(num * -1, base_dec));
		else
			return (ft_base(num, base_dec));
	}
	if (format == 'u')
		return (ft_base((unsigned int)num, base_dec));
	if (format == 'x')
		return (ft_base((unsigned int)num, base_hex_min));
	if (format == 'X')
		return (ft_base((unsigned int)num, base_hex_upp));
	return (1);//Para pensar señores ERROR
}
//LA tocha
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
			if (*aux == 'i'|| *aux == 'd' || *aux == 'u' || *aux == 'x' || *aux == 'X')
				ft_distributor_num(va_arg(argv, int), *aux);
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

//Main pruebitas
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
}