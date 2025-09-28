#include <stdbool.h>
#include <string.h>

bool	isHot(const char *s)
{
	if (!s)
		return (false);
	return (strcmp(s, "alex"));
}
