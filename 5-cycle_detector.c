#include "ft_list.h"

int cycle_detector(const t_list *list)
{
    const t_list *a;
    const t_list *b;

    a = list;
    b = list;

    while (a->next && b->next && b->next->next)
    {
        a = a->next;
        b = b->next->next;
        if (a == b)
            return (1);
    }
    return (0);
}