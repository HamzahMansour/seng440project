#include <stdio.h>
#include <math.h>

unsigned int lookup_table[] = {19, 51, 83, 115, 147, 179, 211, 243};
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

int main(int argc, char *argv[])
{
	// 14-bit input -> max value = 16383 -->  8-bit output -> max value = 255
	// unsigned int sample_array[] = {0, 60, 100, 250, 666, 1000, 3333, 5555, 10000, 16383};
	
	unsigned int sample_array[1<<14];
	for (int i = 0; i < 1<<14; ++i)
	{
		sample_array[i] = i;
	}
	size_t samples = sizeof(sample_array) / sizeof(sample_array[0]);
	printf("samples: %lu\n", samples);
	unsigned int result_array[samples], compare_array[samples], diff_array[samples];
	int max_index = 0, max = 0;
	float compare_value;

	// compute result_array, compare_array, diff_array, and error values
	for (int i = 0; i < samples; ++i)
	{
		result_array[i] = pwlog2(sample_array[i]);
		compare_value = round(256*(log2(1+(255*(float)sample_array[i]/16384)))/8);
		compare_array[i] = (int)compare_value;
		if(compare_array[i] > result_array[i])
			diff_array[i] = compare_array[i] - result_array[i];
		else diff_array[i] = result_array[i] - compare_array[i];
		if(diff_array[i] > max){
			max_index = i;
			max = diff_array[i];
		}
	}

	printf("max_error: %u\nvalue with max_error: %u\n",max,sample_array[max_index]);

	if(argc > 1)
	{
		if(argv[1][0] == 'p')
		{
			// print input arry to test
			printf("sample_array: \t{");
			for (int k = 0; k < samples-2; ++k)
			{
				printf("%u,\t",sample_array[k]);
			}
			printf("%u}\n",sample_array[samples-1]);

			// print output array
			printf("result_array: \t{");
			for (int k = 0; k < samples-2; ++k)
			{
				printf("%u,\t",result_array[k]);
			}
			printf("%u}\n",result_array[samples-1]);

			// print compare array
			printf("compare_array: \t{");
			for (int k = 0; k < samples-2; ++k)
			{
				printf("%u,\t",compare_array[k]);
			}
			printf("%u}\n",compare_array[samples-1]);

			// print diff array
			printf("diff_array: \t{");
			for (int k = 0; k < samples-2; ++k)
			{
				printf("%u,\t",diff_array[k]);
			}
			printf("%u}\n",diff_array[samples-1]);
		}

		// user-input testing
		if(argv[1][0] == 'i'){
			unsigned int a, b;
			while(1){
				printf( "x = "); 
				scanf( "%u", &a); 
				if(a == -1) break;
				b = pwlog2(a); 
				printf( "y = %u\n", b);	
				float c = 256*(log2(1+(255*(float)a/16384)))/8;
				printf("y': %.0f\n", c);
			}
		}
	}
	return 0;
}
