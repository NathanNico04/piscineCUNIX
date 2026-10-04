int int_palindrome(int n)
{
    if (n < 0)
        return 0;

    int reversed = 0;
    int nb = n;
    while (nb > 0)
    {
        reversed = reversed * 10 + nb % 10;
        nb /= 10;
    }
    return reversed == n;
}
