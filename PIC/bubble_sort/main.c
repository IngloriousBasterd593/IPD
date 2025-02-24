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

void bubble_sort(void);

volatile int arr[25] = {
	148, 67, 253, 11, 36, 245, 0, 255, 127, 64,
	89, 50, 15, 99, 234, 128, 1, 200, 33, 90,
	55, 77, 123, 222, 187
};
volatile unsigned long pass, i, j;
volatile unsigned int temp;

void main(void)
{
    TRISA = 0x00;
    while(1)
    {
         PORTA = 0x01; // Turn ON all LED's connected to Port1
         bubble_sort();
         PORTA = 0x00; // Turn OFF all LED's connected to Port1
         bubble_sort();
    }
}

void bubble_sort(void){
	for(pass = 0; pass < 25; pass++){
		for(i = 0; i < 25 - 1; i++){
			for(j = 0; j < 25 - i - 1; j++){
				if(arr[j] > arr[j+1]){
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}
