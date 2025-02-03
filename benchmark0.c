#define DX 10
#define TAYLORDEPTH 10
#define STEP (2 * 3.14159) / DX

static unsigned int factorial(unsigned int n)
{
    unsigned int result = 1;

    for(unsigned int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

static float power(float base, unsigned int exponent)
{
    float result = 1.0;

    for (unsigned int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

static float sint(float x)
{
    float sum = 0.0;

    for (unsigned int n = 0; n < TAYLORDEPTH; n++)
    {
        float sign = (n % 2 == 0) ? 1.0 : -1.0;
        float numerator = power(x, 2 * n + 1);
        float denom = factorial(2 * n + 1);
        sum += sign * (numerator / denom);
    }

    return sum;
}

static float cost(float x)
{
    float sum = 0.0;

    for (unsigned int n = 0; n < TAYLORDEPTH; n++)
    {
        float sign = (n % 2 == 0) ? 1.0 : -1.0;
        float numerator = power(x, 2 * n);
        float denom = factorial(2 * n);
        sum += sign * (numerator / denom);
    }

    return sum;
}

static void benchmark_torus(unsigned int R, unsigned int r)
{
    for(int j = 0; j < DX; j++)
    {
        for(int k = 0; k < DX; k++)
        {
            if(j * STEP > 2 * 3.14159)
            {
                break;
            }

            float garbage = (R + r * cost(STEP * k)) * sint(STEP * j);
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