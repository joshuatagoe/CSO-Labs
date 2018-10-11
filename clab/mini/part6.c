#include <stdio.h>
#include <assert.h>

//extract the 8-bit exponent field of single precision floating point number f 
//and return it as an unsigned byte
unsigned char
get_exponent_field(float f) 
{
unsigned int *num1 = (int *)&f;
*num1 = (*num1) << 1;

unsigned char *num = (unsigned char*) num1;
return num[3];

}

//clear the most significant b bits of unsigned integer number
//return the resulting value
//As an example, suppose unsigned int number = 0xffff0000; int b= 15
//then the correct return value is 65536
//if b = 30, then the return value is 0
//if b = 40, the return value should also be zero
unsigned int
clear_msb(unsigned int number, int b)
{
	int num = number;
	for(int i = 1; i<=b; i++){
		num = num & ~(1<<(32-i));
	}
	return num;
}

//given an array of bytes whose length is array_size (bytes), treat it as a bitmap (i.e. an array of bits),
//and return the bit value at index i (from the left) of the bitmap.
//As an example, suppose char array[3] = {0x00, 0x1f, 0x12}, the corresponding
//bitmap is 0x001f12, thus,
//the bit at index 0 is bitmap[0] = 0
//the bit at index 1 is bitmap[1] = 0
//...
//the bit at index 11 is bitmap[11] = 1
//the bit at index 12 is bitmap[12] = 1
//...
//the bit at index 16 is bitmap[16] = 0
//...
unsigned char
bit_at_index(unsigned char *array, int array_size, int i)
{
	if(i<array_size*8){
		int index = (i)/8;
		unsigned char x = array[index];
		x = x & (1 << (7 - (i - (8*index))));
		if(x){
			return 1;
		}
		return 0;

	}
	
	//TODO: Your code here
	
}