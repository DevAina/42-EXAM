#include "ft_list.h"
#include <stdlib.h>


int cmp(void *a, void *b)
{
    if (a == b)
        return (0);
    return (1);
}
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;

    if (*begin_list != NULL && cmp != NULL && begin_list != NULL && data_ref != NULL)
    {
        current = *begin_list;
        if (cmp(current->data, data_ref) == 0)
        {
            *begin_list = current->next;
            free(current);
            return (ft_list_remove_if(begin_list, data_ref, cmp));
        }
        else
            ft_list_remove_if(&current->next, data_ref, cmp);
    }
}