#include <stdio.h>
#include "pico/stdlib.h"

// Definindo o pino do led 2
#define LED_2 14    

// Definindo pinos do teclado
#define L1 1
#define C2 6

void init_led()
{
    gpio_init(LED_2); // Inicia o Led 2
    gpio_set_dir(LED_2, GPIO_OUT); // Define como saída
    gpio_put(LED_2, 0); // inicia apagado
}

