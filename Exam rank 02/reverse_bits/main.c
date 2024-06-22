#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char   reverse_bits(unsigned char octet);

void    print_bits(unsigned char octet)
{
    unsigned char   mask;

    mask = 0b10000000;
    for (int i = 0; i < 8; i++)
    {
        if (octet & mask)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        mask = mask >> 1;
    }
}

int main(int argc, char **argv)
{
    unsigned char   octet;

    if (argc == 2)
    {
        octet = atoi(argv[1]);
        printf("Original bits\n");
        print_bits(octet);
        write(1, "\n", 1);
        octet = reverse_bits(octet);
        printf("Apres reverse_bits\n");
        print_bits(octet);
    }
    write(1, "\n", 1);
    return (0);
}