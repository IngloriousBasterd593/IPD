#include <REGX52.H>

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

void graf(void);

void main(void)
{
    while(1)
    {
         P1 = 0x01; // Turn ON all LED's connected to Port1
         graf();
         P1 = 0x00; // Turn OFF all LED's connected to Port1
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


