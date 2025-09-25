#include <stdio.h>

// Función que calcula cuántos paréntesis están "mal colocados" en la cadena
// Devuelve la suma de paréntesis abiertos sin cerrar + paréntesis cerrados sobrantes
int invalid(char *s)
{
	int opened = 0; // cuenta de paréntesis '(' abiertos sin cerrar
	int closed = 0; // cuenta de paréntesis ')' sobrantes

	// Recorremos toda la cadena
	for (int x = 0; s[x]; x++)
	{
		if (s[x] == '(')        // si encontramos '(' incrementamos abiertos
			opened++;
		else if (s[x] == ')')   // si encontramos ')'
		{
			if (opened > 0)      // si hay un '(' abierto pendiente
				opened--;        // cerramos uno
			else
				closed++;        // si no hay abiertos, es un ')' sobrante
		}
	}
	// devolvemos el total de paréntesis mal colocados
	return (opened + closed);
}

// Función recursiva que genera todas las combinaciones posibles
// quitando exactamente "to_remove" paréntesis para obtener cadenas válidas
void generate_result(char *s, int to_remove, int deleted, int pos)
{
	// Caso base: si ya hemos quitado todos los paréntesis que debíamos
	// y la cadena resultante no tiene errores
	if (to_remove == deleted && !invalid(s))
	{
		puts(s); // imprimimos la cadena válida
		return;
	}
	// Recorremos la cadena desde la posición actual
	while (s[pos])
	{
		// Solo nos interesa modificar los paréntesis
		if (s[pos] == '(' || s[pos] == ')')
		{
			char c = s[pos];    // guardamos el paréntesis actual
			s[pos] = ' ';       // lo "eliminamos" temporalmente (lo reemplazamos por espacio)
			generate_result(s, to_remove, deleted + 1, pos + 1); // recursión con uno más eliminado
			s[pos] = c;         // restauramos el paréntesis para seguir probando otras combinaciones
		}
		pos++;
	}
}

// Función principal
int main(int ac, char **av)
{
	if (ac != 2) // comprobamos que se pase exactamente un argumento
		return (1);

	int to_remove = invalid(av[1]);   // calculamos cuántos paréntesis hay que eliminar
	generate_result(av[1], to_remove, 0, 0); // llamamos a la función recursiva para generar todas las cadenas válidas
	return (0);
}

