/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_s(char *str)
{
        int i, len = 0;
        char *s;

        if (str != NULL)
                s = str;
        else
                s = "(null)";
        for (i = 0; s[i] != '\0'; i++)
        {
                _putchar(s[i]);
                len++;
        }
        return (len);
}
