#include <unistd.h>   // read, write
#include <stdio.h>    // printf, perror
#include <string.h>   // strlen

int	main(int argc, char **argv)
{
	char	buf[1024];
	ssize_t	len;
	ssize_t	i;
	int		y;

	// Validar argumentos
	if (argc != 2 || argv[1][0] == '\0')
		return (1);

	// Leer en bucles de 1024 bytes
	while ((len = read(0, buf, 1024)) > 0)
	{
		if (len < 0)
		{
			perror("Error");
			return (1);
		}
		buf[len] = '\0';
		i = 0;
		while (i < len)
		{
			y = 0;
			while (argv[1][y] != '\0' && buf[i + y] == argv[1][y])
				y++;
			if (argv[1][y] == '\0')
			{
				// Encontramos la palabra -> imprimir *
				while (y > 0)
				{
					printf("*");
					y--;
				}
				i = i + strlen(argv[1]); // saltar la palabra
			}
			else
			{
				printf("%c", buf[i]);
				i++;
			}
		}
	}
	if (len < 0) // por si read devuelve -1
	{
		perror("Error");
		return (1);
	}
	return (0);
}

/*
ssize_t read(int fd, void *buf, size_t count);
fd:
0 → stdin (entrada estándar, normalmente el teclado o un echo | ./programa).
1 → stdout (salida estándar, pantalla).
2 → stderr (errores).

*buff:
Es un puntero a un espacio de memoria donde read guardará lo que lea.
Debes haber reservado antes ese espacio con malloc o con un array.

count:
el numero máximo de bytes que quieres leer en esa llamada.*/