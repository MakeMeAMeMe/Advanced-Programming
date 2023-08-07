#include "./linked_list.h"
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    uint64_t length;
    LinkedListNode *begin;
    LinkedListNode *end;
};

struct LinkedListNode {
    void *data;
    LinkedListNode *next;
    LinkedListNode *previous;
};

uint32_t _linked_list_insert_begin(LinkedList *linked_list, LinkedListNode *node);
uint32_t _linked_list_insert_end(LinkedList *linked_list, LinkedListNode *node);
LinkedListNode *find_linked_list_from_end(LinkedList *linked_list, uint64_t position);
LinkedListNode *find_linked_list_from_begin(LinkedList *linked_list, uint64_t position);
LinkedListNode *_find_linked_list(LinkedList *linked_list, uint64_t position);

LinkedList *new_linked_list() {
    LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));
    linked_list->length = 0;
    linked_list->begin = NULL;
    linked_list->end = NULL;
    return linked_list;
}

LinkedListNode *new_linked_list_node(uint64_t data_size) {
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    node->data = (void *)malloc(data_size);
    node->next = NULL;
    node->previous = NULL;
    return node;
}

uint32_t linked_list_insert_begin(LinkedList *linked_list, void *data, uint64_t data_size) {
    LinkedListNode *node = new_linked_list_node(data_size);
    memcpy_s(node->data, data_size, data, data_size);
    return _linked_list_insert_begin(linked_list, node);
}

uint32_t _linked_list_insert_begin(LinkedList *linked_list, LinkedListNode *node) {
    node->previous = NULL;
    if (linked_list->begin == NULL) {
        // Empty list
        node->next = NULL;

        linked_list->begin = node;
        linked_list->end = node;

        linked_list->length++;

        return 0;
    }

    LinkedListNode *aux = linked_list->begin;

    node->next = aux;
    linked_list->begin = node;

    aux->previous = node;

    linked_list->length++;
    return 0;
}

uint32_t linked_list_insert_end(LinkedList *linked_list, void *data, uint64_t data_size) {
    LinkedListNode *node = new_linked_list_node(data_size);
    memcpy_s(node->data, data_size, data, data_size);
    return _linked_list_insert_end(linked_list, node);
}

uint32_t _linked_list_insert_end(LinkedList *linked_list, LinkedListNode *node) {
    node->next = NULL;
    if (linked_list->end == NULL) {
        // Empty list
        node->previous = NULL;

        linked_list->begin = node;
        linked_list->end = node;

        linked_list->length++;

        return 0;
    }

    LinkedListNode *aux = linked_list->end;

    node->previous = aux;
    linked_list->end = node;

    aux->next = node;

    return 0;
}

uint32_t linked_list_delete(LinkedList *linked_list, uint64_t position) {
    LinkedListNode *node = _find_linked_list(linked_list, position);

    if (node == NULL) {
        return 1;
    }

    LinkedListNode *prev = node->previous;
    LinkedListNode *next = node->next;

    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->previous = prev;
    }

    if (linked_list->begin == node) {
        linked_list->begin = next;
    }
    if (linked_list->end == node) {
        linked_list->end = prev;
    }

    free(node->data);
    free(node);

    linked_list->length--;

    return 0;
}

void *find_linked_list(LinkedList *linked_list, uint64_t position) {
    LinkedListNode *node = find_linked_list(linked_list, position);
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}
LinkedListNode *_find_linked_list(LinkedList *linked_list, uint64_t position) {
    if (position > linked_list->length) {
        return find_linked_list_from_end(linked_list, position);
    }
    return find_linked_list_from_begin(linked_list, position);
}

LinkedListNode *find_linked_list_from_begin(LinkedList *linked_list, uint64_t position) {
    LinkedListNode *aux = linked_list->begin;

    uint64_t counter = 0;
    while (aux != NULL) {
        if (counter++ == position) {
            break;
        }
        aux = aux->next;
    }
    return aux;
}

LinkedListNode *find_linked_list_from_end(LinkedList *linked_list, uint64_t position) {
    LinkedListNode *aux = linked_list->end;

    uint64_t counter = linked_list->length - 1;
    while (aux != NULL) {
        if (counter-- == position) {
            break;
        }
        aux = aux->previous;
    }
    return aux;
}
