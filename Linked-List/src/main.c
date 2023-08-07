#include <stdio.h>

#include "linked_list.h"

int main(int argc, char const* argv[]) {
    // instantiate a list
    LinkedList* linked_list = new_linked_list();
    // add 3 elements
    linked_list_insert_begin(linked_list, (void*)1, sizeof(int));
    linked_list_insert_begin(linked_list, (void*)2, sizeof(int));
    linked_list_insert_begin(linked_list, (void*)3, sizeof(int));
    // find 2 of them
    int aux = (int)find_linked_list(linked_list, 0);
    printf("valor 0: %d\n", aux);
    aux = (int)find_linked_list(linked_list, 2);
    printf("valor 2: %d\n", aux);
    // remove all 3
    linked_list_delete(linked_list, 0);
    linked_list_delete(linked_list, 1);
    linked_list_delete(linked_list, 2);
    return 0;
}
