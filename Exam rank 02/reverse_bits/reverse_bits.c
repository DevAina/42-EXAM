unsigned char   reverse_bits(unsigned char octet)
{
    unsigned char   rev_octet;
    int             i;

    rev_octet = 0;
    i = 0;
    while(i < 8)
    {
        rev_octet = (rev_octet << 1) | (octet & 1);
        octet = octet >> 1;
        i++;
    }
    return (rev_octet);
}