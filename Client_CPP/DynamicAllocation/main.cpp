#include <iostream>
#include <stdlib.h>
struct MyStruct
{
	int a;
};

int main() {

	// c에서 동적할당
	struct MyStruct* a = (struct MyStruct*)malloc(sizeof(struct MyStruct));
	free(a);

	// c++ 에서 동적할당
	// new 키워드를 사용
	// 타입* 포인터이름 = new 타입;
	MyStruct* myStruct = new MyStruct;
	delete myStruct;

	int* pi = new int;
	*pi = 100;
	std::cout << *pi << std::endl;
	delete pi;

	return 0;
}