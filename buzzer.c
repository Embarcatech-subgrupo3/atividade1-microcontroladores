#include <stdio.h>
#include "pico/stdlib.h"

#define BUZZER 21

void ativar(){

        gpio_put(BUZZER, 1);
  
}


int main()
{
    stdio_init_all();
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    while (true) {
        
        ativar();
        
    }
}
