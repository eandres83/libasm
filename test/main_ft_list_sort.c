#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_list
{
	void		*data;
	struct s_list	*next;
}	t_list;

void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_push_front(t_list **begin_list, void *data);
int	ft_list_size(t_list *begin_list);
int	ft_strcmp(const char *s1, const char *s2);

static void	print_list(t_list *list)
{
	printf("LISTA: ");
	while (list)
	{
		printf("[%s] -> ", (char *)list->data);
		list = list->next;
	}
	printf("NULL\n");
}

int main()
{
	t_list *lista = NULL;

	printf("=== Test ft_list_sort ===\n\n");

	ft_list_push_front(&lista, "gato");
	ft_list_push_front(&lista, "perro");
	ft_list_push_front(&lista, "caracol");
	ft_list_push_front(&lista, "goat");
	ft_list_push_front(&lista, "dani");

	printf("--- BEFORE ---\n");
	print_list(lista);

	ft_list_sort(&lista, ft_strcmp);

	printf("--- AFTER ---\n");
	print_list(lista);

	while (lista)
	{
		t_list *tmp = lista->next;
		free(lista);
		lista = tmp;
	}

	return (0);
}

