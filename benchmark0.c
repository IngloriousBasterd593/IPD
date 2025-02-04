#define DX 10
#define TAYLORDEPTH 10
#define STEP (2 * 3.14159) / DX

static unsigned int factorial(volatile unsigned int n)
{
    volatile unsigned int result = 1;

    for(volatile unsigned int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

static float power(volatile float base, volatile unsigned int exponent)
{
    volatile float result = 1.0;

    for (volatile unsigned int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

static float sint(volatile float x)
{
    volatile float sum = 0.0;

    for (volatile unsigned int n = 0; n < TAYLORDEPTH; n++)
    {
        volatile float sign = (n % 2 == 0) ? 1.0 : -1.0;
        volatile float numerator = power(x, 2 * n + 1);
        volatile float denom = factorial(2 * n + 1);
        sum += sign * (numerator / denom);
    }

    return sum;
}

static float cost(volatile float x)
{
    volatile float sum = 0.0;

    for (volatile unsigned int n = 0; n < TAYLORDEPTH; n++)
    {
        volatile float sign = (n % 2 == 0) ? 1.0 : -1.0;
        volatile float numerator = power(x, 2 * n);
        volatile float denom = factorial(2 * n);
        sum += sign * (numerator / denom);
    }

    return sum;
}

static void benchmark_torus(volatile unsigned int R, volatile unsigned int r)
{
    for(volatile int j = 0; j < DX; j++)
    {
        for(volatile int k = 0; k < DX; k++)
        {
            if(j * STEP > 2 * 3.14159)
            {
                break;
            }

            volatile float garbage = (R + r * cost(STEP * k)) * sint(STEP * j);
            garbage = (R + r * cost(STEP * k)) * cost(STEP * j);
            garbage = r * sint(STEP * k);
        }
    }
}

int main()
{
    benchmark_torus(109, 50);

    return 0;
}
