#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct  s_list
{
    void    *data;
    struct s_list *next;
}   t_list;

# include <stdlib.h>
# include <stdio.h>

int cmp(void *a, void *b);

#endif