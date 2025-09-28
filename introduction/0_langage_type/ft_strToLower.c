#include <unistd.h>

static int	isUpper(int c)
{
	return ((c >= 'A' && c <= 'Z'));
}

void	ft_strToLower(const char *s)
{
	int	i;
	char	to_print;

	i = 0;
	while (s && s[i])
	{
		if (isUpper(s[i]))
			to_print = s[i] + 32;
		else
			to_print = s[i];
		write(1, &to_print, 1);
		i++;
	}
}
