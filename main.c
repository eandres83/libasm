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
char	*ft_strdup(const char *s);

int main()
{
	printf("\n--- ft_strlen ---\n\n");

	const char *str1 = "";
	const char *str2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	printf("Me: %lu\n", ft_strlen(str1));
	printf("Original: %lu\n", strlen(str1));
	printf("Me: %lu\n", ft_strlen(str2));
	printf("Original: %lu\n", strlen(str2));

	printf("\n--- ft_strcpy ---\n\n");

	char dest[250];
	printf("Me: %s\n", ft_strcpy(dest, str1));
	printf("Original: %s\n", strcpy(dest, str1));
	printf("Me: %s\n", ft_strcpy(dest, str2));
	printf("Original: %s\n", strcpy(dest, str2));

	printf("\n--- ft_strcmp ---\n\n");

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

	printf("\n--- ft_write ---\n\n");

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

	int fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

	errno = 0;
	printf("--- ft_write ---\n");
	ssize_t res = ft_write(fd, "ft_write\n", 9);
	printf("Return value: %ld\n", res);
	printf("Errno value: %d\n", errno);

	
	errno = 0;
	printf("--- write ---\n");
	ssize_t res1 = write(fd, "write_ft\n", 9);
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

	printf("\n--- ft_read ---\n\n");

	lseek(fd, 0, SEEK_SET);
	errno = 0;

	char buffer[100];
	errno = 0;
	printf("--- ft_read ---\n");
	ssize_t leidos = ft_read(fd, buffer, 99);
	buffer[leidos] = '\0';
	printf("Leido (%ld bytes): %s", leidos, buffer);

	lseek(fd, 0, SEEK_SET);
	printf("--- read ---\n");
	leidos = read(fd, buffer, 99);
	buffer[leidos] = '\0';
	printf("Leido (%ld bytes): %s", leidos, buffer);

	printf("--- Test Bad File Descriptor ---\n");
	printf("--- ft_read ---\n");
	leidos = ft_read(-1, buffer, 99);
	printf("Leido (%ld bytes)", leidos);
	printf("Errno: %d\n", errno);

	errno = 0;
	printf("--- read ---\n");
	leidos = read(-1, buffer, 99);
	printf("Leido (%ld bytes)", leidos);
	printf("Errno: %d\n", errno);

	lseek(fd, 0, SEEK_SET);
	printf("--- Test stdin ---\n");
	printf("--- ft_read ---\n");
	leidos = ft_read(0, buffer, 99);
	buffer[leidos] = '\0';
	printf("Leido (%ld bytes): %s", leidos, buffer);

	printf("--- read ---\n");
	leidos = read(0, buffer, 99);
	buffer[leidos] = '\0';
	printf("Leido (%ld bytes): %s", leidos, buffer);

	close(fd);

	printf("\n--- ft_strdup ---\n\n");

	printf("--- ft_strdup ---\n");
	char *strdu = ft_strdup("");
	printf("Original: %s\n", strdu);
	printf("Copia: %s\n", strdu);

	printf("--- strdup ---\n");
	char *strdup1 = ft_strdup("");
	printf("Original: %s\n", strdup1);
	printf("Copia: %s\n", strdup1);

	const char *dup_src = "Hola Dios?????????????????????????????????????????????????????????????????????????????????????????????????????123456789";
	char *dup_res = ft_strdup(dup_src);
	printf("Original: %s\n", dup_src);
	printf("Copia: %s\n", dup_res);

	char *dup_res1 = strdup(dup_src);
	printf("Original: %s\n", dup_src);
	printf("Copia: %s\n", dup_res1);

	free(strdup1);
	free(dup_res);
	free(strdu);

	return (0);
}

