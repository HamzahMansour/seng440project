#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned int pwlog2(unsigned int x) // pwlog2 = piecewise log2
{
	if(x<64)
		return (x*32768)>>16;
	if(x<193)
		return (((x-64)*16257)>>16)+32;
	if(x<461)
		return (((x-193)*8128)>>16)+64;
	if(x<963)
		return (((x-451)*4096)>>16)+96;
	if(x<1999)
		return (((x-963)*2024)>>16)+128;
	if(x<4047)
		return (((x-1999)*1024)>>16)+160;
	if(x<8159)
		return (((x-4047)*510)>>16)+192;
	if(x<16384)
		return (((x-8159)*255)>>16)+224;
	return 0;
}

int main()
{	// 14-bit input -> max value = 16383 -->  8-bit output -> max value = 255
	clock_t begin, end;
	double time_spent;

	unsigned int sample_array[100];
	int i,j;
	for (i = 0, j = 16383; i < 100; ++i, j-=100)
	{
		sample_array[i] = j;
	}

	begin = clock(); // start time recorded
	size_t samples = sizeof(sample_array) / sizeof(sample_array[0]);
	unsigned int result_array[samples];
	for (j = 0; j < 1000000; ++j) // simulate long audio sample
	{
		for (i = 0; i < samples; ++i) // compute result_array
			result_array[i] = pwlog2(sample_array[i]);
	}
	end = clock(); // end time recorded
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // compute time taken
	printf("Time spent: %fs\n", time_spent);
}