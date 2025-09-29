#include <stdbool.h>
#include <string.h>

bool	isHot(const char *s)
{
	//	completer
	(void)s;
	return (false);
}











///////////////////////////////////////////////////////////////////
//	conseil

/*#include <stdlib.h>
void	foo()
{
	//	En c, pour manipuler une string (char *) il faut faire une allocation memoire
	//
	//	En cpp quand t'utilises std::string ca le fait tout seul

	//	Mais manuellement, quand tu alloues, tu liberes, voici un exemple :
	//
	char	*fii;

	fii = malloc(5 * sizeof(char));
	if (!fii)
		return ;
	fii[0] = 'a';
	fii[1] = 'b';
	fii[0] = 'Z';
	fii[2] = '\0';	// caractere nul marque la fin de la chaine
	write(1, fii, 4);
	//	la je n'ai plus besoin de la chaine donc :
	free(fii);
}*/
