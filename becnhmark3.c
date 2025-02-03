static void bubble_sort(unsigned short *arr, unsigned char n)
{
    unsigned int pass, i, j;
   
    for(pass = 0; pass < n; pass++)
    {
        for(i = 0; i < n - 1; i++)
        {
            for(j = 0; j < n - i - 1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    unsigned short temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}



int main()
{

    unsigned short arr[50] = {
    148, 67, 253, 11, 36, 245, 0, 255, 127, 64,
    89, 50, 15, 99, 234, 128, 1, 200, 33, 90,
    55, 77, 123, 222, 187, 11, 67, 241, 2, 69,
    211, 45, 95, 13, 197, 38, 112, 76, 45, 157,
    3, 208, 46, 57, 69, 1, 250, 222, 99, 74
    };

    bubble_sort(arr, 50);

    return 0;
}