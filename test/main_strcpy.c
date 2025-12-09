#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *ft_strcpy(char *dest, const char *str);
size_t	ft_strlen(char *str);

int main()
{
	char str[12] = "Hola Dios?";
	char dest[4];

	char str2[12] = "Hola Dios?";
	char dest2[4];

	char *str3 = NULL;

	ft_strcpy(dest, str);
	write(1, dest, 4);

	write(1, "\n", 1);

	strcpy(dest2, str2);
	write(1, dest2, 4);

	ft_strcpy(dest, str3);
	write(1, dest, 4);

	write(1, "\n", 1);

	strcpy(dest, str3);
	write(1, dest, 4);

	return (0);
}
