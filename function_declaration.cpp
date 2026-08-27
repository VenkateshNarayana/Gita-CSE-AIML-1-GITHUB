#include<stdio.h>
int func_b();
int func_a();
int main(){
	
	printf("function a = %d",func_a());
	
	return 0;
}

int func_a(){
	int x = func_b();
	return x;
}

int func_b(){
	return 10;
}
