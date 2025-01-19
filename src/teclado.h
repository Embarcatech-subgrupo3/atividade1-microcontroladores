#include "pico/stdlib.h"

// Definições dos pinos GPIO
#define L1 1
#define L2 2
#define L3 3
#define L4 4
#define C1 5
#define C2 6
#define C3 7
#define C4 8

// Mapeamento das teclas em uma matriz 4x4
static const char teclas[4][4] = {
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

// Varredura do teclado e retorno da tecla pressionada
char leitura_teclado() {
    for (int row = 0; row < 4; row++) {
        gpio_put(L1 + row, 1);  // Ativa a linha correspondente
        for (int col = 0; col < 4; col++) {
            if (gpio_get(C1 + col)) {  // Verifica se a coluna está ativa
                // sleep_ms(50);          // Debounce
                while (gpio_get(C1 + col)); // Aguarda o botão ser liberado
                gpio_put(L1 + row, 0); // Desativa a linha
                return teclas[row][col];
            }
        }
        gpio_put(L1 + row, 0);  // Garante que a linha é desativada
    }
    return 0; // Retorna 0 se nenhuma tecla for pressionada
}