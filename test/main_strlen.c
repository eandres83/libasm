#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char *str);

int main()
{
	char *str = "Patatas";
	char *str2 = NULL;
	char *str3 = "";
	char *str4 = ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	printf("result me: %lu\n", ft_strlen(str));
	printf("result original: %lu\n", strlen(str));
	printf("result me: %lu\n", ft_strlen(str3));
	printf("result original: %lu\n", strlen(str3));
	printf("result me: %lu\n", ft_strlen(str4));
	printf("result original: %lu\n", strlen(str4));
	printf("result me: %lu\n", ft_strlen(str2));
	printf("result original: %lu\n", strlen(str2));

	return (0);
}

