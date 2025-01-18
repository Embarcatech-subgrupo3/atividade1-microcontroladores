#include <stdio.h>
#include "pico/stdlib.h"

// Definindo o pino do led 2
#define LED_2 14    

// Definindo pinos do teclado
// FAZER

// Inicializando o Led 2
void init_led()
{
    gpio_init(LED_2);
    gpio_set_dir(LED_2, GPIO_OUT);
    gpio_put(LED_2, 0); // inicia apagado
}
