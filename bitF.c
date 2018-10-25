#include <stdio.h>
#include <stdint.h>

#pragma pack(1)
struct data{
	uint8_t ID : 4;
	uint8_t value : 4;
	uint8_t check : 4;
	uint8_t time : 4;
};

int main(){

	struct data d;
	printf("%d\n", sizeof(d));

}