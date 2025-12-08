#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *dest, char *src);

int main()
{
	char s1[5] = "Hola";
	char s2[5] = "Hila";

	printf("result me: %d\n", ft_strcmp(s1, s2));
	printf("result original: %d\n", strcmp(s1, s2));
	return (0);
}

