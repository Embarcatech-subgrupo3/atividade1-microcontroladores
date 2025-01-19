#include <stdio.h>
#include "pico/stdlib.h"

#define LED_3 11
#define L1 1
#define C3 7

void init_pinos() {
    gpio_init(LED_3);
    gpio_set_dir(LED_3, GPIO_OUT);
    gpio_put(LED_3, 0);

    gpio_init(L1);
    gpio_set_dir(L1, GPIO_OUT);
    gpio_put(L1, 0);

    gpio_init(C3);
    gpio_set_dir(C3, GPIO_IN);
    gpio_pull_down(C3);
}

bool leitura_teclado() {
    gpio_put(L1, 1);
    bool pressionado = gpio_get(C3);
    gpio_put(L1, 0);
    if (pressionado) {
        sleep_ms(50); // Adicionei um delay para evitar rebotes
        gpio_put(L1, 1);
        pressionado = gpio_get(C3);
        gpio_put(L1, 0);
    }
    return pressionado;
}

int main() {
    stdio_init_all();
    init_pinos();

    bool led_aceso = false;

    while (1) {
        if (leitura_teclado()) {
            led_aceso = !led_aceso;
            gpio_put(LED_3, led_aceso);
            printf("LED 3 %s\n", led_aceso ? "aceso" : "apagado");
        }
        sleep_ms(100);
    }
}