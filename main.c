#include <stdio.h>
#include "pico/stdlib.h"
#include "./src/LED_1.h"
#include "./src/teclado.h"
#include "./src/LED_2.h"
#include "./src/LED_3.h"
#include "./src/LED_4.h"
#include "./src/buzzer.h"

int main()
{
  init_teclado();
  stdio_init_all();
   printf("Pressione uma tecla!\n");
  while (true)
  {
    led_1();
    led_2();
    led_3();
    led_4();
    buzzer();
  }
}