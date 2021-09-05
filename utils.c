#include "minitalk.h"

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
int ft_atoi(const char *str)
{
	unsigned int num;
	int i;
	int np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' ||
		   str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int n)
{
    unsigned int nb;

    if (n < 0)
        ft_putchar('-');
    nb = n < 0 ? n * -1 : n;
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
    else
        ft_putchar(nb + '0');
}
void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

// int		count_nb(int n)
// {
// 	int		i;

// 	i = 0;
// 	if (n < 0)
// 		i++;
// 	while (n / 10 != 0)
// 	{
// 		i++;
// 		n = n / 10;
// 	}
// 	return (i + 1);
// }

// char	*ft_itoa(int nb)
// {
// 	char	*str;
// 	int		i;
// 	long	n;

// 	i = count_nb(nb);
// 	n = nb;
// 	str = malloc(sizeof(char) * (count_nb(nb) + 1));
// 	if (str != NULL)
// 	{
// 		if (n < 0)
// 		{
// 			str[0] = '-';
// 			n = n * -1;
// 		}
// 		while (n / 10 != 0 && i >= 0)
// 		{
// 			str[i - 1] = (n % 10) + '0';
// 			n = n / 10;
// 			i--;
// 		}
// 		str[i - 1] = n + '0';
// 		str[count_nb(nb)] = '\0';
// 	}
// 	return (str);
// }
