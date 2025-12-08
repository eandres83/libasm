#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char *ft_strdup(const char *s);

int main()
{
	const char *s = "Hola esto es un test";
	char *res;

	printf("--- ft_strdup ---\n");
	res = ft_strdup(s);
	printf("result: %s\n", res);

	free(res);
	return (0);
}

