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

    // add 3 elements
    linked_list_insert(linked_list, (void*)1, sizeof(int), 0);
    linked_list_insert(linked_list, (void*)2, sizeof(int), 0);
    linked_list_insert(linked_list, (void*)-3, sizeof(int), 0);

    // find 2 of them
    for (size_t i = 0; i < 3; i++) {
        int* data = (int*)find_linked_list(linked_list, i);
        int aux = (int)(*data);
        printf("Valor %lu: %d\n", i, aux);
    }

    for (size_t i = 0; i < 3; i++) {
        int* data = (int*)find_value_linked_list(linked_list, (void*)(i + 1), comparator);
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
        void* aux = (int*)find_linked_list(linked_list, i);
        printf("Valor %lu: %p\n", i, aux);
    }

    return 0;
}
