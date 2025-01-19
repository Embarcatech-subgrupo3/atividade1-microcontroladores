#include <stdio.h>
#include "pico/stdlib.h"

// Definindo o pino do led 2
#define LED_2 11    

// Definindo pinos do teclado
#define L1 1
#define C2 6

void init_led()
{
    gpio_init(LED_2); // Inicia o Led 2
    gpio_set_dir(LED_2, GPIO_OUT); // Define como saída
    gpio_put(LED_2, 0); // inicia apagado
}

// Inicializando os pinos do teclado
void init_teclado() 
{
    gpio_init(L1);            // Inicializa a linha 1
    gpio_set_dir(L1, GPIO_OUT);   // Define como saída
    gpio_put(L1, 0);          // Inicializa como baixo

    gpio_init(C2);            // Inicializa a coluna 2
    gpio_set_dir(C2, GPIO_IN);    // Define como entrada
    gpio_pull_down(C2);       // Ativa resistor pull-down
}

// Verifica o teclado e retorna se a tecla foi pressionada
bool leitura_teclado() 
{
    gpio_put(L1, 1);          // Ativa a linha 1
    if (gpio_get(C2))         // Verifica se a tecla está pressionada
    {      
        sleep_ms(50);         
        while (gpio_get(C2)); // Espera a tecla ser solta
        gpio_put(L1, 0);      // Desativa a linha 1
        return true;          // Retorna que a tecla foi pressionada
    }
    gpio_put(L1, 0);          // Desativa a linha 1
    return false;             // Retorna que nenhuma tecla foi pressionada
}

int main() 
{
    stdio_init_all();         // Inicializa a comunicação serial
    init_led();               // Inicializa o LED
    init_teclado();           // Inicializa o teclado

    bool led_aceso = false;   // Variável para controlar o estado do LED

    while (1) 
    {
        if (leitura_teclado()) // Verifica se a tecla foi pressionada
        { 
            led_aceso = !led_aceso;   // Alterna o estado do LED
            gpio_put(LED_2, led_aceso); // Atualiza o LED
            printf("LED 2 %s\n", led_aceso ? "aceso" : "apagado");
        }
        sleep_ms(100);      
    }
}
