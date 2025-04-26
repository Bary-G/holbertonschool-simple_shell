#include <string.h>
#include <ctype.h>

/**
 * trim_spaces - Supprime les espaces au début et à la fin d'une chaîne
 * @str: La chaîne à nettoyer
 */
void trim_spaces(char *str)
{
	char *start = str;
	char *end;

	while (isspace((unsigned char)*start))
        start++;

	if (*start == 0)
	
	{
		*str = 0;
		return;
	}

	end = start + strlen(start) - 1;
	while (end > start && isspace((unsigned char)*end))
        end--;

	*(end + 1) = '\0';

	if (start != str)
        memmove(str, start, end - start + 2);
}

