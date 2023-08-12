#include <stdio.h>

#include "exp_array/exp_array.h"

int main(int argc, char const* argv[]) {
    ExpArray* exp_array = new_exp_array(sizeof(int64_t));
    exp_array_insert(exp_array, (void*)3);
    exp_array_insert(exp_array, (void*)2);
    exp_array_insert(exp_array, (void*)1);

    exp_array_show(exp_array);
    return 0;
}
