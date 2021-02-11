#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
    char *point;
    int len = 0;
    int nbr = 0;
    char *str = "0123456789ABCDEF";

    if (value == 0)
        return "0";

    nbr = value;
    while (nbr)
    {
        nbr = nbr / base;
        len = len + 1;
    }
    nbr = value;
    if (nbr < 0)
    {
        if (base == 10)
            len = len + 1;
        nbr = nbr * -1;
    }
    if (!(point = (char*)malloc(sizeof(char) * (len + 1))))
        return (0);
    
    point[len] = '\0';
    while (nbr)
    {
        point[--len] = str[nbr % base];
        nbr = nbr / base;
    }
    if (value < 0 && base == 10)
        point[0] = '-';
    return (point);
}

#include <stdio.h>
int main (int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s",ft_itoa_base(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}