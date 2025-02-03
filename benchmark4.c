#define CHARLIMIT 255
#define N 5  // Max - 11, grafa virstones

int main()
{
    char d[N][N] = {
        {88, 11, 2, -44, 4},
        {9, -80, 1, 2, 13},
        {2, -1, 0, 1, 40},
        {83, -32, 124, 70, 1},
        {4, 13, -2, 1, 90}
    };
    
    for(unsigned char k = 0; k < N; k++)
    {
        for(unsigned char i = 0; i < N; i++)
        {
            for(unsigned char j = 0; j < N; j++)
            {
                if(d[i][k] != CHARLIMIT && d[k][j] != CHARLIMIT && d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    return 0;
}
