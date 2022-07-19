#include <stdio.h>
#include <stdint.h>

uint32_t my_ntohl (uint32_t n){
	uint32_t n1 = (n & 0xFF000000) >> 24;
	uint32_t n2 = (n & 0x00FF0000) >> 8;
	uint32_t n3 = (n & 0x0000FF00) << 8;
	uint32_t n4 = (n & 0x000000FF) << 24;
	return n1 | n2 | n3 | n4;
}

int main(int argc, char* argv[]){
	char name[] = "안두혁";
	char mobile[] = "7446";
	printf("[bob11]add-nbo[%s%s]", name, mobile);

	uint32_t n,n2;
	FILE* fp = fopen(argv[1], "rb");
	FILE* fp2 = fopen(argv[2], "rb");

	fread(&n,sizeof(uint32_t),1,fp);
	fread(&n2,sizeof(uint32_t),1,fp2);

	int a = my_ntohl(n);
	int b = my_ntohl(n2);
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,a+b,a+b);
}

