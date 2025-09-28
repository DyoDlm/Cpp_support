#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool	test_ft_strlen()
{
	return true;
}

static bool	test_isHot()
{
	return true;
}

static bool	test_ft_strToUpper()
{
	return true;
}

static bool	test_ft_strToLower()
{
	return true;
}

static bool	test_ft_memcpy()
{
	return true;
}

typedef struct enum
{
	STRLEN,
	ISHOT,
	UPPER,
	LOWER,
	MEMCPY,
	OTHER
};

typedef int	(*t_test)(void);

int	main(int ac, char **av)
{
	static const char	*tests[] = {
		"ft_strlen", "isHot", "ft_strToUpper",
		"ft_strToLower", "ft_memcpy", NULL
	};
	static t_test testers[] = {
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
	
	status = testers[test]();
	
	if (status)
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
