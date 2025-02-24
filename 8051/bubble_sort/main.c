#include <REGX52.H>

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
    while(1)
    {
         P1 = 0x01; // Turn ON all LED's connected to Port1
         bubble_sort();
         P1 = 0x00; // Turn OFF all LED's connected to Port1
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
