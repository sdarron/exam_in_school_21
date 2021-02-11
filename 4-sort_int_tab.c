#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    unsigned int j;

    int tmp = 0;

    i = 0;

    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j]; 
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int		main(void)
{
	int tab[] = { -1, 6, 7, 3, -6, 7, 2, 4, 5, 2147483647, -2147483648 };
	unsigned int size = 11;

	sort_int_tab(tab, size);

	unsigned int i = 0;
	while (i < size)
	{
		printf("element %d: %d\n", i, tab[i]);
		i++;
	}
	return 0;
}