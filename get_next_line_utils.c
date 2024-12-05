int count_line_chars(char *str)
{
    int count;

    count = 0;
    while (*str && *str != '\n')
    {
        str++;
        count++;
    }
    return count;
}