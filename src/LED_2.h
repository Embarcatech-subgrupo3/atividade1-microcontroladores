// LED AZUL

#include <stdio.h>
#include "pico/stdlib.h"

// Definição do pino do LED 2
#define LED_2 12

// Definições dos pinos do teclado
#define RL2 1 // ROW LED 2
#define CL2 6 // COL LED 2

bool led_2_aceso = false; // Variável para controlar o estado do LED

// Inicializa o LED 2
void init_led_2()
{
    gpio_init(LED_2);
    gpio_set_dir(LED_2, GPIO_OUT);
    gpio_put(LED_2, 0); // Inicialmente apagado
}

// Inicializa o teclado
void init_teclado_led_2()
{
    gpio_init(RL2);
    gpio_set_dir(RL2, GPIO_OUT);
    gpio_put(RL2, 0);
    gpio_init(CL2);
    gpio_set_dir(CL2, GPIO_IN);
    gpio_pull_down(CL2);
}

// Mantém o LED ligado enquanto o botão for pressionado
int manter_led_2_ligado()
{   
    gpio_put(RL2, 1); // Ativa a linha 1
    int i2 = 1;
    while (gpio_get(CL2)) // enquanto o botão for pressionado
    {
        if (!led_2_aceso)
        {   
            gpio_put(LED_2, true); // Acende o LED 2
            if (i2)
            {
                printf("LED 2 aceso\n");
                i2 = 0;
            }
        }
        led_2_aceso = !led_2_aceso; // Alterna o estado do LED
    }

    gpio_put(RL2, 0); // Desativa a linha 1
    
    if (!i2) printf("LED 2 apagado\n"); // Se não i for igual a 1, significa que
                                // "LED 2 aceso" foi printado;
    return 0;
}

int led_2()
{
    init_led_2();
    init_teclado_led_2();

    manter_led_2_ligado();
    sleep_ms(100);
}