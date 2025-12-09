#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void		*data;
	struct s_list	*next;
}	t_list;

int	ft_list_size(t_list *begin_list);

int main()
{
	t_list *test = malloc(sizeof(t_list));
	if (!test)
		return (0);

	test->data = "Hola";

	test->next = malloc(sizeof(t_list));
	test->next->data = "Adios";

	printf("List size = %d\n", ft_list_size(test));

	free(test);
	return (0);
}
