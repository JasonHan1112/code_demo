#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

typedef struct my_list{
    LIST_HEAD list_node;
    char name[8];
    int index;
}MY_LIST_T;

int init_my_list(MY_LIST_T *my_list, 
                char* name, int index)
{
    int ret = 0;
    INIT_LIST_HEAD(&my_list->list_node);
    memcpy(my_list->name, name, sizeof(my_list->name));
    my_list->index = index;
    return 0;
}

int show_addr_content(MY_LIST_T *my_list)
{
    int ret = 0;
    printf("\n");
    printf("show addr content\n");
    printf("my_list addr = %lu\n", my_list);
    printf("list_entry list addr = %lu\n", container_of(&(my_list->list_node), struct my_list, list_node));
    printf("my_list list_node addr = %lu\n", &my_list->list_node);
    printf("my_list next = %lu\n", my_list->list_node.next);
    printf("my_list prev = %lu\n", my_list->list_node.prev);
    printf("my_list name = %s\n", my_list->name);
    printf("my_list index = %d\n", my_list->index);
    return 0;
}
int main(void)
{
    int ret = 0;
    printf("debug list_head\n");
    MY_LIST_T my_l0;
    init_my_list(&my_l0.list_node, "zero", 0);
    MY_LIST_T my_l1;
    init_my_list(&my_l1, "one", 1);
    list_add_next(&my_l1.list_node, &my_l0.list_node);
    
    MY_LIST_T my_l2;
    init_my_list(&my_l2.list_node, "two", 2);
    list_add_next(&my_l2.list_node, &my_l1.list_node);
    
    MY_LIST_T my_l3;
    init_my_list(&my_l3.list_node, "three", 3);
    list_add_next(&my_l3.list_node, &my_l2.list_node);

    MY_LIST_T my_l4;
    init_my_list(&my_l4.list_node, "four", 4);
    list_add_next(&my_l4.list_node, &my_l3.list_node);

    /*the last node need change*/
    MY_LIST_T my_l5;
    init_my_list(&my_l5.list_node, "five", 5);
    list_add_tail(&my_l5.list_node, &my_l0.list_node);


    show_addr_content(&my_l0);
    show_addr_content(&my_l1);
    show_addr_content(&my_l2);
    show_addr_content(&my_l3);
    show_addr_content(&my_l4);
    show_addr_content(&my_l5);
    
    #if 0/*test list_del interface*/
    list_del(&my_l1.list_node);
    printf("delete 1\n");
    
    list_del_prev(&my_l2.list_node);
    printf("delete 1\n");
    list_del_prev(&my_l2.list_node);
    printf("delete 0\n");

    //list_del_prev(&my_l3.list_node);
    //printf("delete 2\n");

    
    show_addr_content(&my_l0);
    show_addr_content(&my_l1);
    show_addr_content(&my_l2);
    show_addr_content(&my_l3);
    show_addr_content(&my_l4);
    show_addr_content(&my_l5);
    #endif

    #if 1 /*test list for each entry, */
          /*if want to iterate each entry, */
          /*must insert a node as the param of list_for_each_entry*/
    MY_LIST_T *my_l_tmp = NULL;
    
    list_for_each_entry(my_l_tmp, &my_l4.list_node, list_node)
    {
        printf("list for each entry: my_l_tmp->index = %d\n", my_l_tmp->index);
    }
    
    #endif
    return 0;
}