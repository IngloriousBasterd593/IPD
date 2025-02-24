void bubble_sort(void);

volatile int arr[25] = {
	148, 67, 253, 11, 36, 245, 0, 255, 127, 64,
	89, 50, 15, 99, 234, 128, 1, 200, 33, 90,
	55, 77, 123, 222, 187
};

volatile unsigned long pass, i, j;
volatile unsigned int temp;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A2, HIGH);  // turn the LED on (HIGH is the voltage level)
  bubble_sort();                      // wait for a second
  digitalWrite(A2, LOW);   // turn the LED off by making the voltage LOW
  bubble_sort();                      // wait for a second
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
