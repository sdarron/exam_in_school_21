#include <stdlib.h>
#include <stdio.h>

int ft_lennbr(nbr, len)
{
	while (nbr > 0)
	{	
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int len = 0;
	unsigned int nb = 0;
	char *str;
	char *base;

	base = "0123456789";
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
		len = 1;
	else
		len = 0;

	if (nbr < 0)
		nb = -1 * nbr;
	else
		nb = nbr;
	len = ft_lennbr(nb, len);
	if (nbr == 0)
		len = 1;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nb > 0)
	{
		len--;
		str[len] =  base[nb % 10];
		nb = nb / 10;
	}
	if (nbr < 0)
		str[0] = '-';
	return (str);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));
	}
	printf("\n");
	return 0;
}