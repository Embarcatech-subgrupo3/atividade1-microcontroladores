// LED VERMELHO

#include <stdio.h>
#include "pico/stdlib.h"

// Definição do pino do LED 1
#define LED_1 13

// Definições dos pinos do teclado
#define RL1 1 // ROW LED 1
#define CL1 8 // COL LED 1

bool led_1_aceso = false; // Variável para controlar o estado do LED

// Inicializa o LED 1
void init_led_1()
{
    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_put(LED_1, 0); // Inicialmente apagado
}

// Inicializa o teclado
void init_teclado_led_1()
{
    gpio_init(CL1);
    gpio_set_dir(CL1, GPIO_OUT);
    gpio_put(CL1, 0);
    gpio_init(CL1);
    gpio_set_dir(CL1, GPIO_IN);
    gpio_pull_down(CL1);
}

// Mantém o LED ligado enquanto o botão for pressionado
int manter_led_1_ligado()
{   
    gpio_put(CL1, 1); // Ativa a linha 1
    int i1 = 1;
    while (gpio_get(CL1)) // enquanto o botão for pressionado
    {
        if (!led_1_aceso)
        {   
            gpio_put(LED_1, true); // Acende o LED 1
            if (i1)
            {
                printf("LED 1 aceso\n");
                i1 = 0;
            }
        }
        led_1_aceso = !led_1_aceso; // Alterna o estado do LED
    }

    gpio_put(CL1, 0); // Desativa a linha 1
    
    if (!i1) printf("LED 1 apagado\n"); // Se não i for igual a 1, significa que
                                // "LED 1 aceso" foi printado;
    return 0;
}

int led_1()
{
    init_led_1();
    init_teclado_led_1();
    int i1 = 1;
    while (i1--)
    {   
        manter_led_1_ligado();
        sleep_ms(100);
    }
}
