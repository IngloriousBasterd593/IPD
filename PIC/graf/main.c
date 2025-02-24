#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ = 4000000

void graf(void);

#define CHARLIMIT 255
#define N 5  // Max - 11, grafa virstones

volatile unsigned int k = 0;
volatile unsigned int i = 0;
volatile unsigned int j = 0;

volatile int d[N][N] = {
    {88, 11, 2, -44, 4},
    {9, -80, 1, 2, 13},
    {2, -1, 0, 1, 40},
    {83, -32, 124, 70, 1},
    {4, 13, -2, 1, 90}
};

void main(void)
{
    TRISA = 0x00;
    while(1)
    {
         PORTA = 0x01; // Turn ON all LED's connected to Port1
         graf();
         PORTA = 0x00; // Turn OFF all LED's connected to Port1
         graf();
    }
}

void graf(void){
  for(k = 0; k < N; k++){
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        if(d[i][k] != CHARLIMIT && d[k][j] != CHARLIMIT && d[i][k] + d[k][j] < d[i][j]){
            d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
}