#include <stdio.h>
#include "pico/stdlib.h"
#include "./src/LED_1.h"
#include "./src/LED_2.h"
#include "./src/LED_3.h"
#include "./src/LED_4.h"
#include "./src/buzzer.h"
#include "./src/teclado.h"

// Função para desligar todos os LEDs (não desliga o buzzer aqui)
void desligar_todos() {
    gpio_put(LED_1, false);
    gpio_put(LED_2, false);
    gpio_put(LED_3, false);
}

int main() {
    stdio_init_all();  // Inicializa comunicação serial
    init_teclado();    // Inicializa o teclado
    init_led_1();      // Inicializa o LED 1
    init_led_2();      // Inicializa o LED 2
    init_led_3();      // Inicializa o LED 3
    init_led_4();      // Inicializa o LED 4
    ativar_buzzer();   // Inicializa o buzzer

    printf("Pressione uma tecla no teclado!\n");

    while (1) {
        char key = leitura_teclado(); // Lê a tecla pressionada
        if (key) {
            printf("Tecla pressionada: %c\n", key);

            // Desliga todos os LEDs antes de ativar o novo
            desligar_todos();

            // Controle das funcionalidades
            if (key == '1') {
                led_1();  // Aciona LED 1 (vermelho)
            } else if (key == '2') {
                led_2();  // Aciona LED 2 (verde)
            } else if (key == '3') {
                led_3();  // Aciona LED 3 (azul)
            } else if (key == 'A') {
                led_4();  // Liga todos os LEDs
            } else if (key == '4') {
                buzzer();  // Ativa ou desativa o buzzer
            }
        }
        sleep_ms(100); // Evita loop excessivo
    }
}
