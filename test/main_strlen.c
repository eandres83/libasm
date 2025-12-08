#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char *str);

int main()
{
	char *str = "Patatas";

	printf("result me: %lu\n", ft_strlen(str));
	printf("result original: %lu\n", strlen(str));

	return (0);
}

