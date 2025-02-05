
#define WIDTH     32
#define HEIGHT    32
#define MAX_ITER  64
#define SCALE     327

#define FIX_MUL(a, b)  (((long long)(a) * (b)) >> 16)

volatile unsigned int mandelbrot_benchmark(void)
{
    volatile unsigned int sum = 0;
    volatile int x, y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            volatile int cx = (x - (WIDTH/2)) * SCALE;
            volatile int cy = (y - (HEIGHT/2)) * SCALE;
            volatile int zx = 0;
            volatile int zy = 0;
            volatile int iter = 0;
            
            while (iter < MAX_ITER)
            {
                volatile int zx2 = FIX_MUL(zx, zx);
                volatile int zy2 = FIX_MUL(zy, zy);
                if ((zx2 + zy2) >= (4 << 16))
                {
                    break;
                }

                volatile int new_zx = zx2 - zy2 + cx;
                volatile int new_zy = (2 * FIX_MUL(zx, zy)) + cy;
                zx = new_zx;
                zy = new_zy;
                iter++;
            }

            sum += iter;
        }
    }

    return sum;
}

void main()
{
    volatile unsigned int result = mandelbrot_benchmark();

}









