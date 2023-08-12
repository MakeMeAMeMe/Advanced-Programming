#include <gtest/gtest.h>
#include <stdio.h>

#include "../src/linked_list.h"

TEST(LinkedListTest, InsertingAItemMakesAListNotEmpty) {
    LinkedList* linked_list = new_linked_list();
    void* finder = find_linked_list(linked_list, 0);
    printf("%p\n", finder);
    EXPECT_EQ(finder, (void*)NULL);
    int data = 3;
    int* result = (int*)linked_list_insert(linked_list, (void*)&data, sizeof(int), 0);

    EXPECT_EQ(*result, data);

    finder = find_linked_list(linked_list, 0);
    printf("%p\n", finder);
    EXPECT_NE(finder, (void*)NULL);
}
