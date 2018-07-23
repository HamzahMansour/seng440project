#include <stdio.h>

// pwlog2 = piecewise log2
unsigned short int pwlog2(unsigned short int x) 
{
	if(x < (1<<6)) 						// x < 2^6 = 64
		return (0); 					// error
	if(x < (1<<7)) 						// 2^6 < x < 2^7 = 128
		return x - (1<<6); 				// x-2^6
	if(x < (1<<8)) 						// 2^7 < x < 2^8 = 256
		return ((x+1)>>1); 				// x/2
	if(x < (1<<9)) 						// 2^8 < x < 2^9 = 512
		return ((x+2)>>2) + (1<<2);		// x/2^2 + 2^2
	if(x < (1<<10)) 					// 2^9 < x < 2^10 = 2014
		return ((x+4)>>3) + (1<<3);		// x/2^3 + 2^3
	if(x < (1<<11))						// 2^10 < x < 2^11 = 2048
		return ((x+8)>>4) + (1<<4);		// x/2^4 + 2^4
	if(x < (1<<12))						// 2^11 < x < 2^12 = 4096
		return ((x+16)>>5) + (1<<5); 	// x/2^5 + 2^5
	if(x < (1<<13))						// 2^12 < x < 2^13 = 8192
		return ((x+32)>>6) + (1<<6); 	// x/2^6 + 2^6
	if(x < (1<<14))						// 2^13 < x < 2^14 = 16384
		return ((x+64)>>7) + (1<<7); 	// x/2^7 + 2^7
	return (0); 						// error if > 2^14
}

unsigned int compress(unsigned int input)
{
	unsigned int compressed_value = pwlog2(input);
	unsigned int final_value = compressed_value;
	return final_value;
}

int main()
{
	// audio stream represented as integer array (samples)
	// 14-bit input -> max value = 16383
	// 8-bit output -> max value = 256
	unsigned int samples[] = {10, 69, 420, 1500, 6666, 12222, 16383};
	unsigned int results[5]; // store resulting compressed audio stream in an integer array

	int i,j;
	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; i < 7; ++i)
		{
			results[i] = compress(samples[i]);
		}
	}

	// print input arry to test
	printf("samples: {");
	for (int k = 0; k < 6; ++k)
	{
		printf("%u,",samples[k]);
	}
	printf("%u}\n",samples[6]);

	// print output array
	printf("results: {");
	for (int k = 0; k < 6; ++k)
	{
		printf("%u,",results[k]);
	}
	printf("%u}\n",results[6]);

	// user-input testing
	unsigned int a, b;
	while(1){
		printf( "a = "); 
		scanf( "%u", &a); 
		if(a == -1) break;
		printf("%u\n", a);
		b = pwlog2(a); 
		printf( "log2(a) = %hi\n", b);	
	}
	return 0;
}
