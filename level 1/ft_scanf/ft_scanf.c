#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// Detecta y salta espacios en el flujo de entrada
int match_space(FILE *f)
{
	int c = fgetc(f);

	while (c != EOF && isspace(c)) // solo saltamos espacios
		c = fgetc(f);
	if (c != EOF)
		ungetc(c, f); // devolvemos el primer carácter no espacio

	return 0;
}


// Comprueba si el siguiente carácter coincide con c
int match_char(FILE *f, char c)
{
		// Aquí puedes insertar tu código
	return (0);
}

// Lee un carácter y lo almacena mediante va_list
int scan_char(FILE *f, va_list ap)
{
		// Aquí puedes insertar tu código
	return (0);
}

// Lee un entero y lo almacena mediante va_list
int scan_int(FILE *f, va_list ap)
{
		// Aquí puedes insertar tu código
	return (0);
}

// Lee una cadena de caracteres y la almacena mediante va_list
int scan_string(FILE *f, va_list ap)
{
		// Aquí puedes insertar tu código
	return (0);
}

// Decide qué función de lectura usar según la conversión
int match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

// Función que recorre el formato y llama a las funciones de conversión
int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f); // devuelve el carácter al flujo

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

// Función que el usuario llama, equivalente a scanf
int ft_scanf(const char *format, ...)
{
	// Se inicia va_list
	int ret = ft_vfscanf(stdin, format, ap); // usa stdin como flujo
	// ...
	return ret;
}

/*%d → ignora espacios antes, acepta signo opcional, deja de leer cuando no es dígito.

%s → ignora espacios antes, lee hasta encontrar un espacio.

%c → no ignora espacios, lee el siguiente carácter literal.*/
