#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned int pwlog2(unsigned int x) // pwlog2 = piecewise log2
{
	if(x>=16384)
		return -1;
	if(x>=8159)
		return 12271;
	if(x>=4047)
		return 6103;
	if(x>=1999)
		return 3023;
	if(x>=963)
		return 1481;
	if(x>=451)
		return 707;
	if(x>=193)
		return 322;
	if(x>=64)
		return 128;
	return 32;
}

int main(int argc, char *argv[])
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
	for (int j = 0; j < 1000000; ++j) // simulate long audio sample
	{
		for (int i = 0; i < samples; ++i) // compute result_array
			result_array[i] = pwlog2(sample_array[i]);
	}
	end = clock(); // end time recorded
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // compute time taken
	printf("Time spent: %fs\n", time_spent);
}