#include <unistd.h>

int is_print(char c)
{
    return (c >= 33 && c <= 126);
}

void    print_first_word(char *str)
{
    int i;
    int in_word;

    i = 0;
    in_word = 1;
    while (in_word == 1)
    {
        while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
            i++;
        if (is_print(str[i]))
        {
            while (is_print(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            in_word = 0;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        print_first_word(argv[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}