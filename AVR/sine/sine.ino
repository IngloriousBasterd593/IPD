#define M_PI 3.14159265f
#define TABLE_SIZE 30

volatile float raadians;
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

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A2, HIGH);  // turn the LED on (HIGH is the voltage level)
  sine();                      // wait for a second
  digitalWrite(A2, LOW);   // turn the LED off by making the voltage LOW
  sine();                      // wait for a second
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
    // sin(x) ˜ x - (x^3)/6 + (x^5)/120
    x2 = x * x;
    term1 = x;
    term2 = (x * x2) / 6.0f;   // x^3 / 3!
    term3 = (x * x2 * x2) / 120.0f;  // x^5 / 5!

    return term1 - term2 + term3;
}

// Function to calculate sine value and map it to the 0–255 PWM range
int calculate_sine_pwm(float radians) {
    // Calculate sine value (-1.0 to 1.0)
    sine_value = sin_approx(radians);

    // Map sine value from (-1.0 to 1.0) to (0–255)
    return (int)((sine_value + 1.0f) * 127.5f);
}

void sine(void){
	for (i = 0; i < TABLE_SIZE; i++) {
		// Calculate angle in radians (evenly spaced over 0–2p)
		raadians = (float)i * 2.0f * M_PI / (float)TABLE_SIZE;
		sine_table[i] = calculate_sine_pwm(raadians);
	}
}
