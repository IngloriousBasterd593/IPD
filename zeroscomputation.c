
int main()
{
	volatile char i, j, k, n;

	volatile char x[24] = {
		0,  1,  0, -1,  0,  1,  0, -1,
		0,  1,  0, -1,  0,  1,  0, -1,
		0,  1,  0, -1,  0,  1,  0, -1
	};

	volatile char XR[24] = {0};
	volatile char XI[24] = {0};
	volatile char cos_vals[24] = {
		127, 123, 110,  90,  64, 33,  0, -33,
		-64, -90, -110, -123, -127, -123, -110, -90,
		-64, -33,  0,  33,  64,  90,  110, 123
	};

	volatile char sin_vals[24] = {
		0,  33,  64,  90, 110, 123, 127, 123,
		110,  90,  64,  33,   0, -33, -64, -90,
	   -110, -123, -127, -123, -110, -90, -64, -33
	};

	volatile char dummy[4];
	
	n = 24;
	
	for(i = 0; i < n; i++)
	{
		XR[i] = 0;
		XI[i] = 0;

		for(j = 0; j < n; j++)
		{
			k = (i * j) % n;
			XR[i] += x[j] * cos_vals[k];
			XI[i] -= x[j] * sin_vals[k];
		}
	}
	
	for(i = 1; i < n; i++)
	{
		if(XR[i] * XR[i - 1] <= 0)
		{
			return i;
		}
	}
	
	return 0;
}

