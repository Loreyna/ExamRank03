#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	invalid(char *s)
{
	int opened = 0;
	int closed = 0;

	for (int x = 0; s[x]; x++)
	{
		if (s[x] == '(')
			opened++;
		else if (s[x] == ')')
		{
			if (opened > 0)
				opened--;
			else
				closed++;
		}
	}
	return (opened + closed);
}

void	solve(char *s, int must_fix, int fixed, int pos)
{
	if (must_fix == fixed && !invalid(s))
	{
		puts(s);
		return;
	}
	for (int x = pos; s[x]; x++)
	{
		if (s[x] == '(' || s[x] == ')')
		{
			char c = s[x];
			s[x] = ' ';
			solve(s, must_fix, fixed + 1, x + 1);
			s[x] = c;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	int must_fix = invalid(av[1]);
	solve(av[1], must_fix, 0, 0);
	return (0);
}
