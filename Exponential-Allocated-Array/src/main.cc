#include <stdio.h>

#include "exp_array/exp_array.h"

int main(int argc, char const* argv[]) {
    int var_1 = 1;
    int var_2 = 2;
    int var_3 = -3;

    ExpArray* exp_array = new_exp_array(sizeof(int));
    for (size_t i = 0; i < 100; i++) {
        exp_array_insert(exp_array, (void*)&i);
    }

    exp_array_insert(exp_array, (void*)&var_3);
    exp_array_insert(exp_array, (void*)&var_2);
    exp_array_insert(exp_array, (void*)&var_1);

    exp_array_show(exp_array);
    return 0;
}
