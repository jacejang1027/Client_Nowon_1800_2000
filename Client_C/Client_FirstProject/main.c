// #~ : 전처리기, 해당 소스코드 파일의 컴파일을 진행하기 전에 처리할 내용에 대해서 입력함.
#include <stdio.h> // 전처리기를 사용한 헤더파일 선언


// main 함수 : 운영체제에서 실행파일을 실행하면 가장먼저 호출되는 함수. 없으면 컴파일 안됨.
// f(x) : f 를 함수, x 는 매개변수 라고 함
// 주석 : 
// // : 해당 라인 컴파일시 무시
// /* */ : /* 와 */ 사이 내용 컴파일시 무시
// 주석 설정 단축키 : Ctrl + k , c , Ctrl + Shift + Slash
// 주석 해제 단축키 : Ctrl + k , u

// 다중라인선택:
// 단축키 : Alt + Shift 한채로 키보드 화살표 방향키 또는 마우스 클릭/드래그

// 함수의 기본형태
// "출력형태" "함수이름" (매개변수)
// 매개변수가 없고 int 형을 출력하는 함수, 이름은 main
int main(void)
{
	printf("Hello world !");

	// printf
	// 콘솔창에 문자열을 출력하는 함수
	// 호출형태 : printf(서식문자열)
	printf("%d\n", 1);
	return 0;
	// 통상적으로 0을 반환하면 정상적으로 해당 함수가 끝났다는것을 상위 함수에 알려주기 위함.
	// 함수가 기능을 수행한 후에 문제가 있을 경우 0이 아닌 지정된 숫자를 반환하는 방식으로 사용한다.
}