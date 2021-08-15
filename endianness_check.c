#include<stdio.h>
int main(){
	int a=0x56933;
	char *c=(char*)&a;
	if(*c==0x85){
		printf("your architecture is big endian ");
	}
	else{
		printf("your architecture is little endian");
	}
	return 0;
}
//https://cs-fundamentals.com/tech-interview/c/c-program-to-check-little-and-big-endian-architecture
