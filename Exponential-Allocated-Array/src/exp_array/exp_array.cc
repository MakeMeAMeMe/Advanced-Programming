#include "exp_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../Linked-List/src/linked_list.h"

struct ExpArray {
    LinkedList* linked_list;
    uint64_t data_size;
};

typedef struct ExpArrayNode {
    uint64_t limit;
    uint64_t count;
    void* vector;
} ExpArrayNode;

ExpArray* new_exp_array(uint64_t data_size) {
    ExpArray* exp_array = (ExpArray*)malloc(sizeof(ExpArray));
    if (exp_array == NULL) {
        return NULL;
    }
    exp_array->linked_list = new_linked_list();
    if (exp_array->linked_list == NULL) {
        free(exp_array);
        return NULL;
    }
    exp_array->data_size = data_size;
    return exp_array;
}

ExpArrayNode* new_exp_array_node(uint64_t data_size, uint64_t limit) {
    ExpArrayNode* exp_array_node = (ExpArrayNode*)malloc(sizeof(ExpArrayNode));
    if (exp_array_node == NULL) {
        return NULL;
    }
    exp_array_node->count = 0;
    exp_array_node->limit = limit;
    exp_array_node->vector = (void*)malloc(data_size * limit);
    if (exp_array_node->vector == NULL) {
        free(exp_array_node);
        return NULL;
    }
    return exp_array_node;
}

uint32_t exp_array_insert(ExpArray* exp_array, void* data) {
    ExpArrayNode* node = (ExpArrayNode*)linked_list_get_end(exp_array->linked_list);
    if (node == NULL) {
        // if node == NULL, start process
        // alloc first node
        node = new_exp_array_node(exp_array->data_size, 1);
        // add node to ll
        linked_list_insert_end(exp_array->linked_list, node, sizeof(ExpArrayNode));
    } else if (node->count >= node->limit) {
        // if node.count == limit
        // alloc new node
        node = new_exp_array_node(exp_array->data_size, 2 * node->limit);
        // add node to ll
        linked_list_insert_end(exp_array->linked_list, node, sizeof(ExpArrayNode));
    }

    // add item
    memcpy(node->vector + node->count, data, exp_array->data_size);

    node->count++;
    // if node.count < limit
    // add item
    return 0;
}

void exp_array_show(ExpArray* exp_array) {
    uint64_t position = 0;
    while (1) {
        ExpArrayNode* node = ((ExpArrayNode*)find_linked_list(exp_array->linked_list, position++));
        if (node == NULL) {
            break;
        }
        for (uint64_t i = 0; i < node->count; i++) {
            printf("%d ", *((int*)node->vector + i));
        }
        printf("\n");
    }
}
