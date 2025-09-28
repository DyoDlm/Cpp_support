#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool	ft_strlen(void);
bool	isHot(void);
bool	ft_strToUpper(void);
bool	ft_strToLower(void);
bool	ft_memcpy(void);

static bool	test_ft_strlen(void)
{
	return true;
}

static bool	test_isHot(void)
{
	return true;
}

static bool	test_ft_strToUpper(void)
{
	return true;
}

static bool	test_ft_strToLower(void)
{
	return true;
}

static bool	test_ft_memcpy(void)
{
	return true;
}

typedef enum e_types
{
	STRLEN,
	ISHOT,
	UPPER,
	LOWER,
	MEMCPY,
	OTHER
}	t_types;

typedef bool	(*t_test)(void);

int	main(int ac, char **av)
{
	static const char	*tests[] = {
		"ft_strlen", "isHot", "ft_strToUpper",
		"ft_strToLower", "ft_memcpy", NULL
	};
	t_test testers[] = {
		test_ft_strlen, test_isHot, test_ft_strToUpper,
		test_ft_strToLower, test_ft_memcpy, NULL
	};
	int	test = 0;
	int	status;

	if (ac < 2)
		return 1;
	for (int i = 0; i < OTHER; i++)
	{
		if (!strcmp(tests[i], av[1]))
			break ;
		test++;
	}
	if (test == OTHER)
		return (printf("KO\n"));	
	status = testers[test]();

	if (status)
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
