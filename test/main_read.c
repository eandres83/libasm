#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
size_t	ft_strlen(const char *s);

int main()
{
	char str[21];

	int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("error en open"), 1);

	const char *text = "Hola esto es solo una prueba";
	ft_write(fd, text, ft_strlen(text));

	lseek(fd, 0, SEEK_SET); // para volver al principio del fd

	printf("--- ft_read ---\n");

	errno = 0;
	ssize_t res = ft_read(fd, str, 20);
	printf("ft_read return: %ld\n", res);
	printf("ft_read return errno: %d\n", errno);
	if (res > 0)
	{
		str[res] = '\0';
		printf("ft_read content: %s\n", str);
	}

	printf("--- read ---\n");

	errno = 0;
	char str2[21];

	lseek(fd, 0, SEEK_SET);

	ssize_t res2 = read(fd, str2, 20);
	if (res2 > 0)
		str2[res2] = '\0';
	printf("read return: %ld\n", res2);
	printf("read return errno: %d\n", errno);
	printf("read content: %s\n", str2);
	
	return (0);
}

