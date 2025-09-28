#include <unistd.h>

static int	isLower(int c)
{
	return ((c >= 'a' && c <= 'z'));
}

void	ft_strToUpper(const char *s)
{
	int	i;
	char	to_print;

	i = 0;
	while (s && s[i])
	{
		if (isLower(s[i]))
			to_print = s[i] - 32;
		else
			to_print = s[i];
		write(1, &to_print, 1);
		i++;
	}
}
