#include <unistd.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

int is_print(char c)
{
    return (c >= 33 && c <= 126);
}

void    print_last_word(char *str)
{
    int i;
    int end;
    int in_word;

    i = ft_strlen(str) - 1;
    in_word = 1;
    while (in_word == 1)
    {
        while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
            i--;
        if (is_print(str[i]))
        {
            end = i;            
            while (is_print(str[i]))
                i--;
            int start = i + 1;
            while (start <= end && is_print(str[start]))
            {
                write(1, &str[start], 1);
                start++;
            }
            in_word = 0;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        print_last_word(argv[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}