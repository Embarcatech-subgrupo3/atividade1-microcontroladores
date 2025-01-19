#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define BUZZER 21

// Função para ativar o buzzer
void ativar_buzzer() {
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0); // Inicialmente desligado
}

// Gera um tom simples no buzzer
void buzzer_tone(int frequency, int duration_ms) {
    int delay_us = 1000000 / (frequency * 2); // Tempo de meio ciclo
    int cycles = (frequency * duration_ms) / 1000; // Número de ciclos

    for (int i = 0; i < cycles; i++) {
        gpio_put(BUZZER, 1);
        sleep_us(delay_us);
        gpio_put(BUZZER, 0);
        sleep_us(delay_us);
    }
}

// Função para ativar o buzzer com tom fixo
void buzzer() {
    printf("Buzzer tocando\n");
    buzzer_tone(1000, 500); // Frequência de 1000 Hz (1 kHz) por 0,5s
}
