double pi_generator(int precision)
{
    if (precision <= 0)
        return 2;

    double result = 1;
    for (int i = precision; i >= 1; i--)
    {
        double id = i;
        result = 1 + id / (id * 2 + 1) * result;
    }
    return 2 * result;
}
