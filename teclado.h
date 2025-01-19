#include <stdio.h>
#include "pico/stdlib.h"

// Mapeamento das teclas em uma matriz 4x4
char teclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Inicializa o teclado matricial
void init_teclado() {
    gpio_init(L1); gpio_set_dir(L1, GPIO_OUT); gpio_put(L1, 0);
    gpio_init(L2); gpio_set_dir(L2, GPIO_OUT); gpio_put(L2, 0);
    gpio_init(L3); gpio_set_dir(L3, GPIO_OUT); gpio_put(L3, 0);
    gpio_init(L4); gpio_set_dir(L4, GPIO_OUT); gpio_put(L4, 0);

    gpio_init(C1); gpio_set_dir(C1, GPIO_IN); gpio_pull_down(C1);
    gpio_init(C2); gpio_set_dir(C2, GPIO_IN); gpio_pull_down(C2);
    gpio_init(C3); gpio_set_dir(C3, GPIO_IN); gpio_pull_down(C3);
    gpio_init(C4); gpio_set_dir(C4, GPIO_IN); gpio_pull_down(C4);
}


