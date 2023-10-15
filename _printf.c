#include "main.h"
/**
 * _printf - printf function for printing.
 * @format: format string that we should manipulate.
 *
 * Return: int count of the format string (its lenght).
*/
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
for (char c, *p = format; *p; ++p)
{
if (*p == '%')
{
++p;
switch (*p)
{
case 'c':
c = va_arg(args, int);
putchar(c);
++count;
break;
case 's':
for (const char *str = va_arg(args, const char*); *str; ++str)
{
putchar(*str);
++count;
}
break;
case '%':
putchar('%');
++count;
break;
}
}
else
{
putchar(*p);
++count;
}
}
va_end(args);
return (count);
}
