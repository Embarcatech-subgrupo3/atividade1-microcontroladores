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

// Verifica o teclado e retorna a tecla pressionada
char leitura_teclado() {
    gpio_put(L1, 1);  // Ativa a linha 1
    if (gpio_get(C1)) {  // Verifica se a tecla '1' foi pressionada
        sleep_ms(50);  
        while (gpio_get(C1));  // Espera até a tecla ser solta
        gpio_put(L1, 0);  // Desativa a linha 1
        return '1';  // Retorna a tecla '1'
    }
    gpio_put(L1, 0);  // Desativa a linha 1
    return 0;  
}

int main() {
    stdio_init_all();
    init_led();
    init_teclado();

    bool led_aceso = false;  // Variável para controlar o estado do LED

    while (1) {
        char key = leitura_teclado();
        if (key == '1') {
            if (led_aceso) {
                gpio_put(LED_1, 0);  // Apaga o LED 1
                printf("LED 1 apagado\n");
            } else {
                gpio_put(LED_1, 1);  // Acende o LED 1
                printf("LED 1 aceso\n");
            }
            led_aceso = !led_aceso;  // Alterna o estado do LED
        }
        sleep_ms(100); 
    }
}
