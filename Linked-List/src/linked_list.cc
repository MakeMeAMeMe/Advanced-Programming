#include "./linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

struct LinkedList {
    uint64_t length;
    LinkedListNode *begin;
    LinkedListNode *end;
};

struct LinkedListNode {
    void *data;
    LinkedListNode *next;
    LinkedListNode *previous;
    // LinkedListNodeDataType data_type;
};

uint32_t _linked_list_insert_begin(LinkedList *linked_list, LinkedListNode *node);
uint32_t _linked_list_insert_end(LinkedList *linked_list, LinkedListNode *node);
LinkedListNode *find_linked_list_from_end(LinkedList *linked_list, uint64_t position);
LinkedListNode *find_linked_list_from_begin(LinkedList *linked_list, uint64_t position);
LinkedListNode *_find_linked_list(LinkedList *linked_list, uint64_t position);
uint32_t _linked_list_insert(LinkedList *linked_list, LinkedListNode *node, uint64_t position);

LinkedList *new_linked_list() {
    LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));
    if (linked_list == NULL) {
        return NULL;
    };
    linked_list->length = 0;
    linked_list->begin = NULL;
    linked_list->end = NULL;
    return linked_list;
}

LinkedListNode *new_linked_list_node(void *data, uint64_t data_size) {
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = (void *)malloc(data_size);
    if (node->data == NULL) {
        free(node);
        return NULL;
    }
    memcpy(node->data, &data, data_size);
    node->next = NULL;
    node->previous = NULL;
    return node;
}

uint32_t linked_list_insert_begin(LinkedList *linked_list, void *data, uint64_t data_size) {
    LinkedListNode *node = new_linked_list_node(data, data_size);
    if (node == NULL) {
        return 1;
    }
    return _linked_list_insert_begin(linked_list, node);
}

uint32_t linked_list_insert_end(LinkedList *linked_list, void *data, uint64_t data_size) {
    LinkedListNode *node = new_linked_list_node(data, data_size);
    if (node == NULL) {
        return 1;
    }
    return _linked_list_insert_end(linked_list, node);
}

uint32_t linked_list_insert(LinkedList *linked_list, void *data, uint64_t data_size, uint64_t position) {
    if (position > linked_list->length) {
        return 1;
    }
    if (position == 0) {
        return linked_list_insert_begin(linked_list, data, data_size);
    }
    if (position == linked_list->length) {
        return linked_list_insert_end(linked_list, data, data_size);
    }

    LinkedListNode *node = new_linked_list_node(data, data_size);
    if (node == NULL) {
        return 1;
    }
    return _linked_list_insert(linked_list, node, position);
}

uint32_t _linked_list_insert(LinkedList *linked_list, LinkedListNode *node, uint64_t position) {
    uint64_t counter = 0;
    LinkedListNode *aux = linked_list->begin;
    while (counter++ < position) {
        aux = aux->next;
    }

    LinkedListNode *prev = aux->previous;
    // LinkedListNode* next = aux->next;

    prev->next = node;
    aux->previous = node;
    node->previous = prev;
    node->next = aux;

    linked_list->length++;

    return 0;
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
    linked_list->length++;

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
    LinkedListNode *node = _find_linked_list(linked_list, position);
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}

LinkedListNode *_find_linked_list(LinkedList *linked_list, uint64_t position) {
    if (position > linked_list->length / 2) {
        return find_linked_list_from_end(linked_list, position);
    }
    return find_linked_list_from_begin(linked_list, position);
}

LinkedListNode *find_linked_list_from_begin(LinkedList *linked_list, uint64_t position) {
    LinkedListNode *aux = linked_list->begin;

    uint64_t counter = 0;
    while (aux != NULL && counter++ < position) {
        aux = aux->next;
    }
    return aux;
}

LinkedListNode *find_linked_list_from_end(LinkedList *linked_list, uint64_t position) {
    LinkedListNode *aux = linked_list->end;

    uint64_t counter = linked_list->length - 1;
    while (aux != NULL && counter-- > position) {
        aux = aux->previous;
    }
    return aux;
}

void *find_value_linked_list(LinkedList *linked_list, void *value,
                             uint8_t (*comparator)(void *search_term, void *data)) {
    LinkedListNode *aux = linked_list->begin;
    while (aux != NULL) {
        if (comparator(&value, aux->data)) {
            return aux->data;
        }
        aux = aux->next;
    }
    return NULL;
}

uint64_t clear_linked_list(LinkedList *linked_list) {
    LinkedListNode *aux = linked_list->begin;
    while (aux != NULL) {
        LinkedListNode *next = aux->next;
        free(aux->data);
        free(aux);
        aux = next;
    }

    linked_list->begin = NULL;
    linked_list->end = NULL;
    linked_list->length = 0;

    return 0;
}

uint64_t free_linked_list(LinkedList *linked_list) {
    if (clear_linked_list(linked_list) != 0) {
        return 1;
    }
    free(linked_list);
    return 0;
}

uint64_t linked_list_get_length(LinkedList *linked_list) { return linked_list->length; }

void *linked_list_get_start(LinkedList *linked_list) {
    if (linked_list->begin == NULL) {
        return NULL;
    }
    return linked_list->begin->data;
}

void *linked_list_get_end(LinkedList *linked_list) {
    if (linked_list->end == NULL) {
        return NULL;
    }
    return linked_list->end->data;
}
