#include <stdio.h>

#include "exp_array/exp_array.h"

int main(int argc, char const* argv[]) {
    ExpArray* exp_array = new_exp_array(sizeof(int64_t));
    exp_array_insert(exp_array, (void*)3);
    return 0;
}
