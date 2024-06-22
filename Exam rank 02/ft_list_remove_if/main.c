#include "ft_list.h"

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

t_list *lst_new(void *data)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (new == NULL)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

void ft_list_add_back(t_list **list, t_list *new)
{
    t_list *tmp;

    if (*list == NULL)
        *list = new;
    else
    {
        tmp = *list;
        while (tmp->next!= NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void print_list(t_list *list)
{
    while (list!= NULL)
    {
        printf("%s\n", (char *)list->data);
        list = list->next;
    }
}

void free_list(t_list *list)
{
    t_list *tmp;

    while (list!= NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main(void)
{
    t_list  *list;

    printf("Creation du donnée...\n");
    list = lst_new("Faniry");
    ft_list_add_back(&list, lst_new("Mario"));
    ft_list_add_back(&list, lst_new("Luigi"));
    ft_list_add_back(&list, lst_new("Peach"));
    ft_list_add_back(&list, lst_new("Toad"));
    ft_list_add_back(&list, lst_new("Bowser"));
    ft_list_add_back(&list, lst_new("Yoshi"));
    printf("Supprimer une donnée grâce à un référence\n");
    ft_list_remove_if(&list, "Luigi", &cmp);
    print_list(list);
    free_list(list);
    return (0);
}