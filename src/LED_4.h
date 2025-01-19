// TODOS OS LEDS

#include <stdio.h>
#include "pico/stdlib.h"

// Definição do pino do LED 1
#define LED_3 11
#define LED_2 12
#define LED_1 13

// Definições dos pinos do teclado
#define CL4 1
#define RL4 8

bool led_4_aceso = false; // Variável para controlar o estado do LED

// Inicializa o LED 1
void init_led_4()
{
    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_put(LED_1, 0); // Inicialmente apagado

    gpio_init(LED_2);
    gpio_set_dir(LED_2, GPIO_OUT);
    gpio_put(LED_2, 0); // Inicialmente apagado

    gpio_init(LED_3);
    gpio_set_dir(LED_3, GPIO_OUT);
    gpio_put(LED_3, 0); // Inicialmente apagado
}

// Inicializa o teclado
void init_teclado_led_4()
{
    gpio_init(CL4);
    gpio_set_dir(CL4, GPIO_OUT);
    gpio_put(CL4, 0);
    gpio_init(RL4);
    gpio_set_dir(RL4, GPIO_IN);
    gpio_pull_down(RL4);
}

// Mantém o LED ligado enquanto o botão for pressionado
int manter_led_4_ligado()
{   
    gpio_put(CL4, 1); // Ativa a linha 1
    int i4 = 1;
    while (gpio_get(RL4)) // enquanto o botão for pressionado
    {
        if (!led_4_aceso)
        {   
            gpio_put(LED_1, true); // Acende o LED 1
            gpio_put(LED_2, true); // Acende o LED 2
            gpio_put(LED_3, true); // Acende o LED 3
            if (i4)
            {
                printf("Todos os LEDs acesos\n");
                i4 = 0;
            }
        }
        led_4_aceso = !led_4_aceso; // Alterna o estado do LED
    }

    gpio_put(CL4, 0); // Desativa a linha 1
    
    if (!i4)  printf("Todos os LEDs apagados\n");

    return 0;
}

void led_4() {
    led_4_aceso = !led_4_aceso; // Alterna o estado
    gpio_put(LED_1, led_4_aceso);
    gpio_put(LED_2, led_4_aceso);
    gpio_put(LED_3, led_4_aceso);

    if (led_4_aceso) {
        printf("Todos os LEDs acesos\n");
    } else {
        printf("Todos os LEDs apagados\n");
    }
}
