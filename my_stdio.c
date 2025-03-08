#include <unistd.h>
#include "my_stdio.h"
#include <stdarg.h>

// 1文字を標準出力に書き出す関数
int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_puts(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        my_putchar(s[i]);
        i++;
    }
    my_putchar('\n');
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, *format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    my_putchar(*str);
                    str++;
                }
            }
        }
        else if (*format == 'd')
        {
            int buffer[12];
            int num = va_arg(args, int);
            int i = 0;

            num++;
            while (num)
            {
                buffer[i++] = (num % 10) + '0';
                num /= 10;
            }

            while (i--)
            {
                my_putchar(buffer[i]);
            }
        }
        else
        {
            my_putchar(*format);
        }
        format++;
    }
    va_end(args);
    return 0;
}