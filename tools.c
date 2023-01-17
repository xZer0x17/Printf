#include "printf.h"
//Para printear:
static int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}
//Para el tema de las bases
static int	ft_base(size_t num, char *base)
{
	size_t	len;

	len = 1;
	if (num >= (size_t)ft_strlen(base))
	{
		len += ft_base(num / ft_strlen(base), base);
		ft_putchar(base[num % ft_strlen(base)]);
	}
	else
		ft_putchar(base[num]);
	return (len);
}
//Para printear el string de forma "tradicional"
static int	ft_putstr(char const *str)
{
	return(write(1, str, ft_strlen(str)));
}

static int	ft_error(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
