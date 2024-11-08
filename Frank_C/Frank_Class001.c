#include<stdio.h> //standard i/o input/output
#include<stdint.h>
//new headfile:Is able to avoid using %
#include<inttypes.h>
#include<float.h>


int main() {
	//printf/scanf
	//print+format  scan+format
	
	__int16 sunflower = 100;
	
	//int sum=3;

	printf("Size of unsigned int: %zu byte(s)\n", sizeof(unsigned int));

	printf("Size of short: %zu byte(s)\n", sizeof(short));
	
	//Below is the type conversion
	//Using ...Max can create the maxium value of a statement
	
	uint16_t Lnum = UINT16_MAX+1;
	int32_t Nnum = INT32_MAX;

	
	printf("%d\n", Nnum);

	//You can easily see the overflow phenomenon,below is what would happen when you force it to transform
	int32_t nnum = (int32_t)Lnum;
	printf("%d\n", Nnum);

	//The result stays the same.Which means that whatever you do ,you can't change the maxium of a statement.
	//test headfile inttypes
	printf("%" PRId32 "\n", Nnum);


	

	float temperture = 36.5f;

	float humidity = 48.3f;

	float speed_of_sound = 343.5e2f;

	float length = 12.34f, width = 23.45f, height = 34.56;

	printf("Temperture : %f\n", temperture);
	printf("Humidity : %f\n", humidity);
	printf("Speed of Sound : %f\n", speed_of_sound);
	printf("Dimensions : %f x %f x %f\n", length, width, height);

	float sound_num = FLT_MAX;


	

	return 0;





//高级汇编语言

//visual basic

	
}