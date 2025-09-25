#include <unistd.h>
#include <stdio.h>
#include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void ft_filter(char *line, char *str)
{
	int i = 0;
	int h = 0;
	int len = strlen(str);
	
	while(line[i])
	{
		h = 0;
		while(str && line[h + i] == str[h])
			h++;
		if(h == len)
		{
			while(h > 0)
			{
				write(1, "*", 1);
				h--;
			}
			i += len;
		}
		else
		{
			write(1, &line[i], 1);
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	char line[999999];
	int read_byte = 1;
	int i = 0;
	
	if(argc != 2 || !argv[1][0])
		return(1);
	while(read_byte > 0)
	{
		read_byte = read(0, &line[i], BUFFER_SIZE);
		if(read_byte == -1)
		{
			perror("Error:");
			return(1);
		}
		i += read_byte;
	}
	line[i] = '\0';
	ft_filter(line, argv[1]);
	return(0);
}
