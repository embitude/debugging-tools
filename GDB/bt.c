#include <stdio.h>

void func1();
void func2();

int main() {
	int i=10;
	func1();
	printf("In Main(): %d\n",i);
}
void func1() {
	int n=20;
	printf("In func1(): %d\n",n);
	func2();
}
void func2() {
	int n = 30;
	printf("In func2() : %d\n",n);
}
