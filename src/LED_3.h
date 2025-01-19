// LED VERDE

#include <stdio.h>
#include "pico/stdlib.h"

// Definição do pino do LED 3
#define LED_3 11

// Definições dos pinos do teclado
#define RL3 1 // ROW LED 3
#define CL3 7 // COL LED 3

bool led_3_aceso = false; // Variável para controlar o estado do LED

// Inicializa o LED 3
void init_led_3()
{
    gpio_init(LED_3);
    gpio_set_dir(LED_3, GPIO_OUT);
    gpio_put(LED_3, 0); // Inicialmente apagado
}

// Inicializa o teclado
void init_teclado_led_3()
{
    gpio_init(RL3);
    gpio_set_dir(RL3, GPIO_OUT);
    gpio_put(RL3, 0);
    gpio_init(CL3);
    gpio_set_dir(CL3, GPIO_IN);
    gpio_pull_down(CL3);
}

// Mantém o LED ligado enquanto o botão for pressionado
int manter_led_3_ligado()
{   
    gpio_put(RL3, 1); // Ativa a linha 1
    int i3 = 1;
    while (gpio_get(CL3)) // enquanto o botão for pressionado
    {
        if (!led_3_aceso)
        {   
            gpio_put(LED_3, true); // Acende o LED 3
            if (i3)
            {
                printf("LED 3 aceso\n");
                i3 = 0;
            }
        }
        led_3_aceso = !led_3_aceso; // Alterna o estado do LED
    }

    gpio_put(RL3, 0); // Desativa a linha 1
    
    if (!i3) printf("LED 3 apagado\n"); // Se não i for igual a 1, significa que
                                // "LED 3 aceso" foi printado;
    return 0;
}

void led_3() {
    led_3_aceso = !led_3_aceso; // Alterna o estado do LED
    gpio_put(LED_3, led_3_aceso); // Atualiza o estado físico do LED
    if (led_3_aceso) {
        printf("LED 3 aceso\n");
    } else {
        printf("LED 3 apagado\n");
    }
}