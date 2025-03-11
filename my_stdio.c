#include <unistd.h>
#include "my_stdio.h"
#include <stdarg.h>

#ifndef EOF
#define EOF (-1)
#endif
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
    va_start(args, format); // *format ではなく format を渡す

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd') // %d の処理
            {
                char buffer[12]; // 数値のバッファ
                int num = va_arg(args, int);
                int i = 0, is_negative = 0;

                // 0 の処理（そのまま '0' を格納）
                if (num == 0)
                {
                    buffer[i++] = '0';
                }
                else
                {
                    // 負の数の処理
                    if (num < 0)
                    {
                        is_negative = 1;
                        num = -num;
                    }

                    // 数値を文字列に変換
                    while (num)
                    {
                        buffer[i++] = (num % 10) + '0';
                        num /= 10;
                    }

                    // 負の数なら '-' を追加
                    if (is_negative)
                    {
                        buffer[i++] = '-';
                    }
                }

                // 逆順に出力
                while (i--)
                {
                    my_putchar(buffer[i]);
                }
            }
            else if (*format == 's') // %s の処理
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    my_putchar(*str);
                    str++;
                }
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

int my_getchar(void)
{
    char c;
    return (read(0, &c, 1) > 0) ? c : EOF;
}

int my_scanf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd')
            {
                int *num = va_arg(args, int *);
                int i = 0, c;
                char buffer[20];

                // 先頭の空白をスキップ
                while ((c = my_getchar()) == ' ' || c == '\n');

                // 負の数の処理
                if (c == '-') {
                    buffer[i++] = c;
                    c = my_getchar();
                }

                // 数値をバッファに格納
                while (c >= '0' && c <= '9' && i < 19)
                {
                    buffer[i++] = c;
                    c = my_getchar();
                }
                buffer[i] = '\0';  // 文字列終端

                // 文字列を整数に変換
                *num = 0;
                int sign = 1, j = 0;
                if (buffer[0] == '-') {
                    sign = -1;
                    j = 1;
                }
                for (; buffer[j] != '\0'; j++) {  // NULL 終端を考慮
                    *num = *num * 10 + (buffer[j] - '0');  // 10進数計算
                }
                *num *= sign;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int i = 0, c;

                // 先頭の空白をスキップ
                while ((c = my_getchar()) == ' ' || c == '\n');

                // 文字列を取得
                while (c != ' ' && c != '\n' && i < 99) {
                    str[i++] = c;
                    c = my_getchar();
                }
                str[i] = '\0';  // 文字列終端
            }
        }
        format++;
    }

    va_end(args);
    return 0;
}
