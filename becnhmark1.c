typedef struct {
    unsigned int a, b;
    unsigned int c, d;
} Matrix;

static Matrix multiply(volatile Matrix x, volatile Matrix y)
{
    volatile Matrix result;

    result.a = x.a * y.a + x.b * y.c;
    result.b = x.a * y.b + x.b * y.d;
    result.c = x.c * y.a + x.d * y.c;
    result.d = x.c * y.b + x.d * y.d;

    return result;  // Atgriežot "result", no volatile kvalifikācijas, tas tiks ignorēts atgriešanas laikā.
}


static Matrix matrix_power(volatile Matrix base, volatile unsigned short exponent)
{
    volatile Matrix result = {1, 0, 0, 1};

    while(exponent > 0)
    {
        if(exponent & 1)
        {
            result = multiply(result, base);
        }

        base = multiply(base, base);
        exponent >>= 1;
    }

    return result;
}


static unsigned int fibonacci(volatile unsigned short n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }

    volatile Matrix base = {1, 1, 1, 0};
    volatile Matrix result = matrix_power(base, n - 1);
   
    return result.a;
}

int main()
{
    volatile unsigned int fib = fibonacci(96);

    return 0;
}
