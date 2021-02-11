#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int nb;
    int i;

    i = 2;
    nb = 0;
    if (argc != 2)
    {
        printf("\n");
        return (0);
    }
    nb = atoi(argv[1]);
    
    if (nb == 1)
    {
        printf("1\n");
        return (0);
    }
    while (i <= nb)
    {
        if (nb % i == 0)
        {
            printf("%d", i);
            if (nb / i > 1)
                printf("*");
            nb = nb / i;
            i--;
        }
        i++;
    }
    printf("\n");
    return (0);
}
