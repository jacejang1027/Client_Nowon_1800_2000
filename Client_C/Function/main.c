#include <stdio.h>



// 반환형 함수이름 (매개변수1자료형 매개변수1이름, 매개변수2자료형 매개변수2이름 )
// {
//		연산내용
//		반환문 (return 반환값) 
// }

// 전역변수 : 모든 곳에서 접근할 수 있는 변수

int globalConut;


// 데이터 영역에 저장되는 변수들 ( 전역변수, 정적변수 ) 은 선언과 동시에 0 으로 초기화된다.


int main(void) {
	
	for (int i = 0; i < 5; i++)
	{
		doSomething();
	}

	int testNum1 = 3;
	int testNum2 = 5;
	// 함수의 호출 형태
	// 함수이름(인자1, 인자2,  ...)
	sum(testNum1, testNum2);

	sum(2, 3);
	sum(4, 3); // 한번 정의 된 함수는 여러번 호출 가능.(함수호출시 정의된 함수를 복사해서 사용함) 


	double* pd1, * pd2, d1, d2;
	d1 = 2.0;
	d2 = 4.0;
	pd1 = &d1;
	pd2 = &d2;


	// 대입연산자 쓰지말고 *pd1. *pd2, d1, d2 의 조합으로 6을 출력할 수 있는
	// 4가지 경우를 써보세요 ( 각 변수는 연산에 한번씩만 사용 가능 )

	printf("%lf\n", d1 + d2);
	printf("%lf\n", *pd1 + *pd2);
	printf("%lf\n", d1 + *pd2);
	printf("%lf\n", *pd1 + d2);

	
	

	// 상수형 포인터
	// 형태 : const 자료형 *
	// 포인터를 바꿀 수 없다는게 아니라 포인터가 가리키는 해당 주소의 값을 바꿀 수 없도록함.
	// 즉, 간접참조연산을 L-value 로 사용할 수 없다.
	int n1 = 0, n2 = 0;
	const int* pa = &n1;
	pa = &n2;
	//*pa = 20; // 불가능.
	n1 = *pa; // 가능
	// const (상수형) 의 사용목적 : 변하지 않으면서 특정 값을 보기편하게 나타낼때 사용

	const int n3 = 0; // n3 은 const 이지만
	int* pn3 = &n3;
	*pn3 = 3; // 간접참조를 통해 n3 의 번지수에 접근하면 
			  // n3 식별자를 거치지 않으므로 해당 주소의 값을 수정할 수가 있다.
	printf("%d\n", n3);

	// 다른 자료형 포인터간의 대입
	// L-value 대입한 포인터의 자료형이 더 크다면 할당ㅂ다지 못한 공간에 접근하는 위험한 상황이
	// 발생할 수 있으므로 주의해야함. 컴파일 에러는 아님.


	int* _n = 3;
	double _d = 3.5;
	int* _p = &_n;
	double* _pd = &_d; 


	/*printf("p : %p\n", _p);
	printf("pd : %p\n", _pd);
	p = pd;
	printf("p : %p\n", _p);
	printf("pd : %p\n", _pd);
	*p = 3;
	printf("size of *p %d\n", sizeof(*_p));
	printf("%d\n", *_p);
	pd = p;
	*pd = 3.5;
	printf("size of *pd %d\n", sizeof(*_pd));
	printf("%d\n", *_pd); */

	printf("p : %p\n", _p);
	printf("pd : %p\n", _pd);
	p = pd;
	printf("p : %p\n", _p);
	printf("pd : %p\n", _pd);
	*p = 3;
	printf("size of *p %d\n", sizeof(*_p));
	printf("%d\n", *_p);
	pd = p;
	*pd = 3.5;
	printf("size of *pd %d\n", sizeof(*_pd));
	
	int* pc = NULL;
	if (pc != NULL)
		printf("%p", pc);

	
	// 포인터를 사용하는 이유
	// swap 에서
	int a = 1, b = 2;
	// 함수호출
	printf("a = %d, b = %d\n", a, b): // 예상결과 a = 2, b = 1;




	return 0;
}

void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
	 
	
}








int doSomething() {
	

	//int globalConut = 0; // 지역변수는 해당 중괄호 밖에서 정의된 모든 같은 이름의 변수보다 우선순위다.
	
	// static : 정적 키워드 , static 으로 선언되면 동적으로 메모리할당이 불가능하다. 프로그램이 끝날때까지 지워지지 않도록 데이터 영역에 저장된다.
	static int localCount = 0; // 정적 지역변수 : 데이터영역에 저장되어 프로그램이 끝날때까지 지워지지는 않지만, 해당 중괄호 안에서만 접근 가능하다.

	localCount++;
	globalConut++;
	printf("doSomething has been called : %d timgs\n", globalConut);
	printf("doSomething has been called : %d timgs(static local)\n", localCount);

	if (localCount < 10) {
		doSomething(); // 재귀함수 : 함수 내에서 동일한 함수 호출
	}
	return 0;


}

// 매개변수도 지역변수 ( 매개변수 지역변수 )

int sum(int a, int b) {

	int tmpValue = a + b;
	printf("%d\n", tmpValue); // 함수 내에서도 함수 호출 가능
	return tmpValue;
}

int sub(int a, int b) {

	// register 변수
	// 해당 변수를 빠른 연산을 위해서 메모리에 할당하지 말고 register 에 직접 할당을 시도하는 키워드
	// 만약에 register 키워드를 사용하느나게 적절하지 않다고 컴파일러가 판단하면 register에 할당하지 않는다.

	int tmpValue = a - b;
	printf("%d\n", tmpValue); // 함수 내에서도 함수 호출 가능
	return tmpValue;

}

