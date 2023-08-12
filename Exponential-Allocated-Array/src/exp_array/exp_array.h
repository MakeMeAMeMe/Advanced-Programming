#pragma once

#include <inttypes.h>

typedef struct ExpArray ExpArray;

ExpArray* new_exp_array(uint64_t data_size);
uint32_t exp_array_insert(ExpArray* exp_array, void* data);
void exp_array_show(ExpArray* exp_array);
