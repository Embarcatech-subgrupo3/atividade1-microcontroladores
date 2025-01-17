#include <stdio.h>
#include "pico/stdlib.h"

// Definição do pino do LED 1
#define LED_1 13

// Definições dos pinos do teclado (simplificado para a tecla 1)
#define L1 1
#define C1 5

// Inicializa o LED 1
void init_led() {
    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_put(LED_1, 0);  // Inicialmente apagado
}

// Inicializa o teclado
void init_teclado() {
    gpio_init(L1); gpio_set_dir(L1, GPIO_OUT); gpio_put(L1, 0);
    gpio_init(C1); gpio_set_dir(C1, GPIO_IN); gpio_pull_down(C1);
}

