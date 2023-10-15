#include "main.h"
/**
* int_printf = a function similar to printf in c.
* @*format = its the format string.
* @... = its the variadic or variable arguments passed.
* Return count : returning the count of the string format. 
*/
int _printf(const char *format, ...)
{
	const char* p = format;
	int count = 0;
	char c;
	int d;
	int i;
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
	{	const char *str = va_arg(list, const char *);
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
