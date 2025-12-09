#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	void		*data;
	struct s_list 	*next;
}	t_list; 

void	ft_list_push_front(t_list **begin_list, void *data);

void	print_list(t_list *list)
{
	while (list)
	{
		printf("[%s] -> ", (char*)list->data);
		list = list->next;
	}
	printf("NULL\n");
}

int main()
{
	t_list *begin_list = NULL;

	ft_list_push_front(&begin_list, "Tercero");
	print_list(begin_list);

	ft_list_push_front(&begin_list, "Segundo");
	print_list(begin_list);

	ft_list_push_front(&begin_list, "Primero");
	print_list(begin_list);

	while (begin_list)
	{
		t_list *tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}

	return (0);
}

