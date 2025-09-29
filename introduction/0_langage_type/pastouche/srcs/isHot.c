#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	len(const char *s)
{
	int	i = 0;

	while (s && s[i])
		i++;
	return (i);
}

static int	isLo(int c)
{
	return ((c >= 'A' && c <='Z'));
}

static char	*upper(const char *s)
{
	int	i = 0;
	char	*up = malloc(len(s) + 1);
	if (!up)
		return NULL;
	while (s && s[i])
	{
		char	c = s[i];
		if (isLo(s[i]))
			c += 32;
		up[i] = c;
		i++;
	}
	up[i] = '\0';
	return (up);
}

bool	isHot(const char *s)
{
	if (!s)
		return (false);
	char *up = upper(s);
	int dif = strcmp(up, "seite");
	free(up);
	return !dif;
}
/*
int	main()
{
	const char	*s1 = "aacjn";
	const char	*s2 = "SEITE";
	const char	*s3 = "seiTe ";
	
	if (isHot(s1))
		printf("OK\n");
	else
		printf("1 not ok\n");
        if (isHot(s2))
                printf("OK\n");
	else
		printf("2 not ok\n");
        if (isHot(s3))
                printf("OK\n");
	else
		printf("3 not ok\n");
	return 0;
}*/


