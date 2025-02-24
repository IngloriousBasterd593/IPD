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

#define M_PI 3.14159265f
#define TABLE_SIZE 30

volatile float radians;
volatile float x2;
volatile float term1;
volatile float term2;
volatile float term3;
volatile float sine_value;
volatile int i;

volatile int sine_table[TABLE_SIZE];


void sine(void);
int calculate_sine_pwm(float radians);
float sin_approx(float x);

void main(void)
{
    TRISA = 0x00;
    while(1)
    {
         PORTA = 0x01; // Turn ON all LED's connected to Port1
         sine();
         PORTA = 0x00; // Turn OFF all LED's connected to Port1
         sine();
    }
}

float sin_approx(float x) {
    // Normalize x to the range -p to p
    while (x > M_PI) {
        x -= 2.0f * M_PI;
    }
    while (x < -M_PI) {
        x += 2.0f * M_PI;
    }

    // Taylor series expansion up to the 5th term:
    // sin(x) ? x - (x^3)/6 + (x^5)/120
    x2 = x * x;
    term1 = x;
    term2 = (x * x2) / 6.0f;   // x^3 / 3!
    term3 = (x * x2 * x2) / 120.0f;  // x^5 / 5!

    return term1 - term2 + term3;
}

// Function to calculate sine value and map it to the 0?255 PWM range
int calculate_sine_pwm(float radians) {
    // Calculate sine value (-1.0 to 1.0)
    sine_value = sin_approx(radians);

    // Map sine value from (-1.0 to 1.0) to (0?255)
    return (int)((sine_value + 1.0f) * 127.5f);
}

void sine(void){
	for (i = 0; i < TABLE_SIZE; i++) {
		// Calculate angle in radians (evenly spaced over 0?2p)
		radians = (float)i * 2.0f * M_PI / (float)TABLE_SIZE;
		sine_table[i] = calculate_sine_pwm(radians);
	}
}
