unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned int num_size = 8 * sizeof(value);
    roll = roll % num_size;
    return (value << roll) | (value >> (num_size - roll));
}
