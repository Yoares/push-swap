#include "linked.h"

t_list *ft_lstnew(void* node)
{
    t_list *new_node;
    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = node;
    new_node->next = NULL;
    return new_node;
}
int main()
{
    char *str = "hello yasser";
    t_list* node = ft_lstnew(str);

     if (node) 
    {
        printf("Node created successfully!\n");
        printf("Node data: %s\n", (char *)node->data);
        printf("Node data: %s\n", (char *)node->next);
    }
}
