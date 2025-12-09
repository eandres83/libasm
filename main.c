#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
size_t	ft_strlen(const char *s);
int	ft_strcmp(char *dest, char *src);
char	*ft_strcpy(char *dest, const char *str);

int main()
{
	printf("--- ft_strlen ---\n\n");

	const char *str1 = "";
	const char *str2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	printf("Me: %lu\n", ft_strlen(str1));
	printf("Original: %lu\n", strlen(str1));
	printf("Me: %lu\n", ft_strlen(str2));
	printf("Original: %lu\n", strlen(str2));

	printf("--- ft_strcpy ---\n\n");

	char dest[250];
	printf("Me: %s\n", ft_strcpy(dest, str1));
	printf("Original: %s\n", strcpy(dest, str1));
	printf("Me: %s\n", ft_strcpy(dest, str2));
	printf("Original: %s\n", strcpy(dest, str2));

	printf("--- ft_strcmp ---\n\n");

	char *temp1 = "";
	char *temp2 = "";
	char *temp3 = "Hola";
	char *temp4 = "Hila";

	printf("Me: %d\n", ft_strcmp(temp1, temp2));
	printf("Original: %d\n", strcmp(temp1, temp2));
	printf("Me: %d\n", ft_strcmp(temp1, temp3));
	printf("Original: %d\n", strcmp(temp1, temp3));
	printf("Me: %d\n", ft_strcmp(temp3, temp2));
	printf("Original: %d\n", strcmp(temp3, temp2));
	printf("Me: %d\n", ft_strcmp(temp3, temp4));
	printf("Original: %d\n", strcmp(temp3, temp4));

	printf("--- ft_write ---\n\n");

	errno = 0;
	printf("--- ft_write ---\n");
	ssize_t ret = ft_write(1, "Hola\n", 5);
	printf("Return value: %ld\n", ret);
	printf("Errno value: %d\n", errno);

	errno = 0;
	printf("--- write ---\n");
	ssize_t ret_original = write(1, "Hola\n", 5);
	printf("Return value: %ld\n", ret_original);
	printf("Errno value: %d\n", errno);

	printf("--- Test Open File Descriptor ---\n");

	int fd = open("file.txt", O_CREAT | O_RDWR | 7777);

	errno = 0;
	printf("--- ft_write ---\n");
	ssize_t res = ft_write(fd, "ft_write\n", 9);
	printf("Return value: %ld\n", res);
	printf("Errno value: %d\n", errno);

	
	errno = 0;
	printf("--- write ---\n");
	ssize_t res1 = write(fd, "write\n", 9);
	printf("Return value: %ld\n", res1);
	printf("Errno value: %d\n", errno);

	printf("--- Test Bad File Descriptor ---\n");

	errno = 0;
	printf("--- ft_write ---\n");
	ssize_t ret1 = ft_write(-1, "Hola\n", 5);
	printf("Return value: %ld\n", ret1);
	printf("Errno value: %d\n", errno);

	errno = 0;
	printf("--- write ---\n");
	ssize_t ret_original1 = write(-1, "Hola\n", 5);
	printf("Return value: %ld\n", ret_original1);
	printf("Errno value: %d\n", errno);

	printf("--- ft_read ---\n\n");
}

