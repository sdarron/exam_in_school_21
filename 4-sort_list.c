#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>


int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *tmp;
    int nb = 0;

    tmp = lst;

    while (lst->next)
    {
        if ((cmp(lst->data, lst->next->data)) == 0)
        {
            nb = lst->data;
            lst->data = lst->next->data;
            lst->next->data = nb;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return (lst);
}


t_list *head; // global variable to excess the list.

t_list *ft_create(int item) // function to create a new node in list
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	new->data = item;
	new->next = NULL;
	return (new);
}

static int  push(int item) // will push the item to the list
{
	t_list *new = ft_create(item);
	if (!new)
		return 0;
	new->next = head;
	head = new;
	return 1;
}


void ft_print(t_list *h) // Function to print the elements in the list.
{
	if (h == NULL)
		return ;
	else
	{
		printf("%d ", h->data);
		ft_print(h->next);
	}
}
int main (void) // main driver
{
	int arr[10] = {1, 9, 15, 4, 5, 12, 7, 3, 9, -5};
	push(arr[0]);
	push(arr[1]);
	push(arr[2]);
	push(arr[3]);
	push(arr[9]);

	int (*cmp)(int, int) = &ascending; // functional pointer which will compare the elements and return 1 or 0;
	sort_list(head, cmp); // sort list will sort the elements in ascending order.
	ft_print(head); // print all the elements in the list.
	return 0;
}