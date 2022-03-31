#include <stdio.h>
// 구조체
// 여러 변수들을 멤버로 가질 수 있는 사용자 정의 자료형

//struct 구조체자료형이름 {
//
//	// 멤버 선언
//};

// 구조체는 값 참조
struct Coord {
	int x;
	int y;
};

typedef struct Student {
	char name[20]; // 20 byte
	double average; // 8 byte
	int korean, english, math;
} Student;

// 비트필드
// 메모리 낭비를 줄일 수 있는 방법으로, 첫번째 멤버부터 순차적으로 비트를 할당 할 수 있다.
// 단, 값이 해당 비트수를 넘어가게되면 오버플로가 발생하니 유의해서 사용해야한다.
struct Time {
	unsigned int sec : 6; // LSB ~ Bit5
	unsigned int min : 6; // Bit6 ~ Bit11
	unsigned int hour : 5; //Bit12 ~ BIt16 
};


struct StudentList {
	struct Student students[3];
	int num;
} studentList;

void
SwapStudents(Student* student1, Student* student2);

int main() {

	struct Coord coord1;
	// . 연산자 (멤버연산자)
	coord1.x = 4;
	coord1.y = 8;
	

	struct Coord coord2;
	coord2 = coord1;

	coord2.x = 1;
	coord2.y = 2;
	printf("좌표1 : (%d, %d)\n", coord1.x, coord1.y);
	printf("좌표2 : (%d, %d)\n", coord2.x, coord2.y);
	
	// 구조체의 메모리 할당
	printf("Coord Size : %d\n", sizeof(struct Coord));

	printf("Student : %d\n", sizeof(struct Student));

	struct Student studentA;
	struct Student* student_P;
	
	strcpy(studentA.name, "Luke");
	studentA.english = 80;
	studentA.korean = 60;
	studentA.math = 40;
	studentA.average = (double) (studentA.english + studentA.korean + studentA.math) / 3.0;

	printf("%s", studentA.name);
	printf("%lf", studentA.average);

	student_P = &studentA;

	// -> 연산자 ( 간접멤버연산자 : 구조체 포인터 변수의 멤버에 접근하는 연산자 )
	
	printf("%s", student_P->name);
	student_P->english = 10;
	printf("%d", student_P->english);
	printf("%d", studentA.english);


	// 구조체 변수의 멤버의 주소에는 접근할 수 있다.
	int* koreanGrade = &studentA.korean;


	printf("\n");
	// 비트필드
	struct Timet1;
	struct Time t1;
	printf("%d\n", sizeof(t1));

	t1.hour = 5;
	t1.min = 12;
	t1.sec = 80;
	printf("%d:%d:%d\n", t1.hour,t1.min, t1.sec);
	//unsigned int* tmpHour = &t1.hour; 비트필드의 주소에는 접근할 수 없다.

	struct Student studentB = {
		{"Tom"},
		{85},
		{25},
		{62},
		{(double)(85 + 25 + 62) / 3.0}
	};
	struct Student studentC = {
		{"Tom"},
		{85},
		{25},
		{62},
		{(double)(85 + 25 + 62) / 3.0}
	};

	// 구조체를 멤버로가지는 구조체
	studentList.num = 3;
	studentList.students[0] = studentA;
	studentList.students[1] = studentB;
	studentList.students[2] = studentC;
	printf("stdent A' english grade %d\n", studentList.students[0].english);

	// 구조체를 스왑하는 함수
	
	struct StudentList {
		struct Student students[3];
		int num;
	} studentList;





	int a = 1, b = 5;
	int* ap = &a;
	int* bp = &b;

	ap = bp;
	*ap = 3;
	*bp = 8;

}

void SwapStudents(Student* student1, Student* student2)
{
	Student tmpStudent = *student1;
	*student1 = *student2;
	*student2 = tmpStudent;
}
