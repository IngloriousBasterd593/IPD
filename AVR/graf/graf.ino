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

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A2, HIGH);  // turn the LED on (HIGH is the voltage level)
  test();                      // wait for a second
  digitalWrite(A2, LOW);   // turn the LED off by making the voltage LOW
  test();                      // wait for a second
}


void test(){
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