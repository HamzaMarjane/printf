#include "main.h"
/**
 * _printf - printing and handling formats.
 * @format : format string that we should manipulate.
 * 
 * Return : the count of the format string (its lenght).
*/

int _printf(const char *format, ...)
{
char c;
int count = 0;
const char *p = format;
va_list list;
va_start(list,format);
if (format == NULL || (format[0] == '%' && !format[1]))
			return (-1);
while (*p != '\0')
{
    if (*p == '%')
    {
        p++;
        count++;
        switch (*p)
        {
        case 'c':
        {
            c = (char)va_arg(list,int);
            _putchar(c);
            break;
        }
            case 's':
            {
            const char *str = va_arg(list,const char*);
            while (*str != '\0')
            {
                _putchar(*str);
                str++;
                count++;
            }
            break;
            }
            case '%':
            {
                _putchar('%');
                count++;
            }
        
            
            
        
        default:
            break;
        }
    }
           else{
            _putchar(*p);
            count++;
        }
        p++;
}
        return (count);
}
