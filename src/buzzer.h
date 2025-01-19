#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define BUZZER 21

// Definições dos pinos do teclado (tecla A)
#define Linha1 2
#define Coluna4 5

bool buz_on = false; // Estado inicial do buzzer (desligado)

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
    gpio_pull_down(Coluna4);
}

// Verifica o teclado e retorna a tecla pressionada
char ligar_buzzer()
{
    gpio_put(Linha1, 1); // Ativa a linha 1
    int b = 1;
    while (gpio_get(Coluna4)) // Se o botão for acionado
    {   
        if (!buz_on)
        {
            gpio_put(BUZZER, true); // Liga o buzzer
            if (b)
            {
                printf("Buzzer tocou\n");
                b = 0;
            }
        }
        
        buz_on = !buz_on;
    }

    gpio_put(Linha1, 0); // Desativa a linha 1
    
    return 0;
}

int buzzer()
{
    ativar_buzzer();
    ativar_teclado();

    int b = 1;
    while (b--)
    {   
        ligar_buzzer();
        sleep_ms(100);
    }
}