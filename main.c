#include <stdio.h>
#include "pico/stdlib.h"
#include "./src/LED_1.h"
#include "./src/LED_2.h"
#include "./src/LED_3.h"

int main()
{
  stdio_init_all(); // inicializa comunicação serial
  
  while (true)
  {
    led_1();
    led_2();
    led_3();
  }
}