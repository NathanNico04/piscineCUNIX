unsigned int greatest_divisor(unsigned int n)
{
    unsigned int i = n / 2;
    while (i > 1)
    {
        if (n % i == 0)
            return i;
        i--;
    }
    return 1;
}
