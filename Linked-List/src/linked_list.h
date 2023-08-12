#pragma once

#include <stdint.h>

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

// typedef enum LinkedListNodeDataType LinkedListNodeDataType;

LinkedList* new_linked_list();
uint32_t linked_list_insert_begin(LinkedList* linked_list, void* data, uint64_t data_size);
uint32_t linked_list_insert_end(LinkedList* linked_list, void* data, uint64_t data_size);
uint32_t linked_list_insert(LinkedList* linked_list, void* data, uint64_t data_size, uint64_t position);
uint32_t linked_list_delete(LinkedList* linked_list, uint64_t position);
void* find_linked_list(LinkedList* linked_list, uint64_t position);
void* find_value_linked_list(LinkedList* linked_list, void* search_term,
                             uint8_t (*comparator)(void* search_term, void* data));
uint64_t clear_linked_list(LinkedList* linked_list);
uint64_t free_linked_list(LinkedList* linked_list);

uint64_t linked_list_get_length(LinkedList* linked_list);
void* linked_list_get_start(LinkedList* linked_list);
void* linked_list_get_end(LinkedList* linked_list);
