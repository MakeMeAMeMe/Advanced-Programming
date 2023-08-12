#include <stdio.h>

#include "linked_list.h"

uint8_t comparator(void* search_term, void* data) {
    if (*((int*)search_term) == *((int*)data)) {
        return 1;
    }
    return 0;
}

int main(int argc, char const* argv[]) {
    // instantiate a list
    LinkedList* linked_list = new_linked_list();

    int var_1 = 1;
    int var_2 = 2;
    int var_3 = -3;

    // add 3 elements
    linked_list_insert(linked_list, (void*)&var_1, sizeof(int), 0);
    linked_list_insert(linked_list, (void*)&var_2, sizeof(int), 0);
    linked_list_insert(linked_list, (void*)&var_3, sizeof(int), 0);

    // find 2 of them
    for (size_t i = 0; i < 3; i++) {
        int* data = (int*)find_linked_list(linked_list, i);
        int aux = (int)(*data);
        printf("Valor %lu: %d\n", i, aux);
    }

    for (size_t i = 0; i < 3; i++) {
        int search_value = i + 1;
        int* data = (int*)find_value_linked_list(linked_list, (void*)&search_value, comparator);
        if (data == NULL) {
            continue;
        }
        int aux = (int)(*data);
        printf("Valor %lu: %d\n", i, aux);
    }

    // remove all 3
    linked_list_delete(linked_list, 0);
    linked_list_delete(linked_list, 0);
    linked_list_delete(linked_list, 0);

    for (size_t i = 0; i < 3; i++) {
        void* aux = (int**)find_linked_list(linked_list, i);
        printf("Valor %lu: %p\n", i, aux);
    }

    return 0;
}
