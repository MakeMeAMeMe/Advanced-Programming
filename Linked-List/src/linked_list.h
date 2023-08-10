#pragma once

#include <stdint.h>

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

// typedef enum LinkedListNodeDataType LinkedListNodeDataType;

LinkedList* new_linked_list();
uint32_t linked_list_insert_begin(LinkedList*, void*, uint64_t);
uint32_t linked_list_insert_end(LinkedList*, void*, uint64_t);
uint32_t linked_list_insert(LinkedList*, void*, uint64_t, uint64_t);
uint32_t linked_list_delete(LinkedList*, uint64_t);
void* find_linked_list(LinkedList*, uint64_t);
void* find_value_linked_list(LinkedList*, void*, uint8_t (*f)(void*, void*));
uint64_t clear_linked_list(LinkedList*);
uint64_t free_linked_list(LinkedList*);
