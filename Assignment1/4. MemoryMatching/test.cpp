#include <iostream>
#include <stdlib.h>

int Sum(a, b, c){
	a=b+c;
	b=a+c;
	c=a+b;
}

int main(){
	int x = 2;
	int y = 3;

	Sum(x,y,y);

	return 1;
}