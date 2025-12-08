#include <stdio.h>
#include <unistd.h>
#include <errno.h>

ssize_t	ft_write(int fd, const void *buf, size_t count);

int main()
{
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

	return (0);
}

