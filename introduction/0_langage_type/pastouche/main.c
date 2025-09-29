#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t	ft_strlen(const char *s);
bool	isHot(const char *s);
void	ft_strToUpper(const char *s);
void	ft_strToLower(const char *s);
void	*ft_memcpy(void *dst, void *src, size_t dst_size);

static bool	test_ft_strlen(void)
{
	size_t	len;
	
	len = ft_strlen("aaa");
	printf("len : %ld\n", len);
	len = ft_strlen("");
        printf("len : %ld\n", len);
        len = ft_strlen(NULL);
	printf("len : %ld\n", len);
        len = ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        printf("len : %ld\n", len);
        len = ft_strlen("aa aa aa aa ");
        printf("len : %ld\n", len);
        len = ft_strlen("zub zub");
        printf("len : %ld\n", len);
	return true;
}

static bool	test_isHot(void)
{
	static char	*personnes[] = {
		"seite", "Seite", "SeITe", "SehIte", "SEITE", "THOMAS", "COHEN",
		"MORE TESTS ...", NULL
	};

	for (int i = 0; personnes[i]; i++)
		isHot(personnes[i]) ? printf("%s is Hot\n", personnes[i]) : printf("%s is not Hot\n", personnes[i]);
	(void)isHot(NULL);
	return true;
}

static bool	test_ft_strToUpper(void)
{
	static char	*strs[] = {"abc", "12345", "aec3w5ac", "c'est une belle journee", 
		"qu'est ce que je fous devant un ordi 13njc!!!?#a", "", "Thomas s'est-il bouge le cul ???", NULL
	};
	for (int i = 0; strs[i]; i++)
		ft_strToUpper(strs[i]);
	ft_strToUpper(NULL);
	return true;
}

static bool	test_ft_strToLower(void)
{
	static char     *strs[] = {"abc", "12345", "aec3w5ac", "c'est une belle journee",
                "qu'est ce que je fous devant un ordi 13njc!!!?#a", "", "Thomas s'est-il bouge le cul ???", NULL
        };

        for (int i = 0; strs[i]; i++)
                ft_strToLower(strs[i]);
        ft_strToLower(NULL);

	return true;
}

#include <stdlib.h>
#include <string.h>

static bool	test_ft_memcpy(void)
{
        static char     *strs[] = {"abc", "12345", "aec3w5ac", "c'est une belle journee",
                "qu'est ce que je fous devant un ordi 13njc!!!?#a", "", "Thomas s'est-il bouge le cul ???", NULL
        };
	char	*dst;

	printf("\nIn\n");
	for (int i = 0; strs[i]; i++)
	{
		dst = malloc((strlen(strs[i]) + 1) * sizeof(char));
		dst = ft_memcpy(dst, strs[i], strlen(strs[i]));
		printf("For str is : %s\nDst is : %s\n", strs[i], dst);
		free(dst);
	}
	printf("\nOut\n");
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
		"ft_strToLower", "ft_mempy", NULL
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
	(void)status;
	return (0);
}
