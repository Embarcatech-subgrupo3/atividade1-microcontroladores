#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define BUZZER 21

// Definições dos pinos do teclado (tecla A)
#define Linha1 8
#define Coluna4 28

// Função para ativar o buzzer
void ativar_buzzer()
{
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Inicializar o teclado
void ativar_teclado()
{
    gpio_init(Linha1);
    gpio_set_dir(Linha1, GPIO_OUT);
    gpio_put(Linha1, 0); // Inicia a linha desativada

    gpio_init(Coluna4);
    gpio_set_dir(Coluna4, GPIO_IN);
    gpio_pull_up(Coluna4); // Ativa pull up na coluna
}

// Verifica o teclado e retorna a tecla pressionada
int leitura_tecla()
{
    gpio_put(Linha1, 1); // Ativa a linha 1
    if (gpio_get(Coluna4))
    {                 // Verifica se a tecla 'A' foi pressionada
        sleep_ms(50); // Debounce
        while (gpio_get(Coluna4))
            ;                // Aguarda até a tecla ser solta
        gpio_put(Linha1, 0); // Desativa a linha 1
        return 'A';          // Retorna a tecla 'A'
    }
    gpio_put(Linha1, 0); // Desativa a linha 1
    return 0;            // Retorna 0 se nenhuma tecla foi pressionada
}

int buzzer(bool buz_on)
{
    char tecla = leitura_tecla();
    if (tecla == 'A')
    { // Se a tecla 'A' foi pressionada alterar o estado atual do buzzer
        if (buz_on)
        {
            gpio_put(BUZZER, 0); // Desliga o buzzer
        }
        else
        {
            gpio_put(BUZZER, 1); // Liga o buzzer
        }
        buz_on = !buz_on; // Alterna o estado do flag buzzer
    }
    sleep_ms(200); // Pequeno atraso para evitar repetições indesejadas
    return buz_on;
}

int ligar_buzzer()
{
    ativar_buzzer();
    ativar_teclado();

    bool buz_on = true; // Estado inicial do buzzer (desligado)

    while (true)
    {
        buzzer(buz_on);
    }
}
