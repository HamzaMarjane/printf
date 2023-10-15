#include "main.h"

int _printf(const char *format, ...)
{
char c;
int d;
int i;
int count =0;
const char* p = format;
va_list list;
va_start(list,format);

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
                count++;
                putchar(c);
                break;
            }
                case 's':
                {
                    const char *str = va_arg(list, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    
                    }
                    break;
                }
                    case '%':
                    {
                        putchar('%');
                        count++;
                        break;
                    }

                     case 'd':
            {
                d = va_arg(list,int);
                count++;
                putchar(d + '0');
                break;
            }

            case 'i':
            {
                i = va_arg(list,int);
                count++;
                putchar(i + '0');
                break;
            }




                
            
            default:
                break;
            }       

    }
    else{
        putchar(*p);
        count++;
    }
    p++;
}
va_end(list);
return count;




}
