#pragma once

#include <stdint.h>

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

LinkedList* new_linked_list();
uint32_t linked_list_insert_begin(LinkedList*, void*, uint64_t);
uint32_t linked_list_insert_end(LinkedList*, void*, uint64_t);
uint32_t linked_list_insert(LinkedList*, void*, uint64_t, uint64_t);
uint32_t linked_list_delete(LinkedList*, uint64_t);
void* find_linked_list(LinkedList*, uint64_t);
uint64_t clear_linked_list(LinkedList*);
uint64_t free_linked_list(LinkedList*);
