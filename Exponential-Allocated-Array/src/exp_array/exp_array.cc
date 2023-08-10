#include "exp_array.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../../Linked-List/src/linked_list.h"

struct ExpArray {
    LinkedList* linked_list;
    uint64_t item_size;
    
};

typedef struct ExpArrayNode {
    uint64_t limit;
    uint64_t count;
    void* vector;
} ExpArrayNode;

ExpArray* new_exp_array(uint64_t item_size) {
    ExpArray* exp_array = (ExpArray*)malloc(sizeof(ExpArray));
    if (exp_array == NULL) {
        return NULL;
    }
    exp_array->linked_list = new_linked_list();
    if (exp_array->linked_list == NULL) {
        free(exp_array);
        return NULL;
    }
    exp_array->item_size = item_size;
    return exp_array;
}

ExpArrayNode* new_exp_array_node(uint64_t item_size, uint64_t limit) {
    ExpArrayNode* exp_array_node = (ExpArrayNode*)malloc(sizeof(ExpArrayNode));
    if (exp_array_node == NULL) {
        return NULL;
    }
    exp_array_node->count = 0;
    exp_array_node->limit = limit;
    exp_array_node->vector = (void*)(malloc(item_size * limit));
    if (exp_array_node->vector == NULL) {
        free(exp_array_node);
        return NULL;
    }
    return exp_array_node;
}

uint32_t array_insert(ExpArray* exp_array, void* data) {

}
