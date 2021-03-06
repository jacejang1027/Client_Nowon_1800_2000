#include <stdio.h>

// 공용체 union
// union 에서 가장 사이즈가 큰 멤버의 데이터 크기만큼 공간 할당
// 나머지멤버들은 해당 공간을 공유함.

typedef union _Jobinfo {
	char schoolName[20];
	char companyName[20];
} Jobinfo;

typedef struct _Person {
	char name[20];
	Jobinfo jobinfo;
} Person;


int main() {

	Person a, b;

	
	strcpy(a.name, "Luke");
	strcpy(a.jobinfo.schoolName, "KoreaSchool");

	strcpy(b.name, "Dina");
	strcpy(b.jobinfo.companyName, "StrongCompany");

	printf("Luke's schoolName : %s\n", a.jobinfo.schoolName);
	printf("Luke's companyName : %s\n", a.jobinfo.companyName);
	printf("DIna's schoolName : %s\n", b.jobinfo.schoolName);
	printf("Dina's companyName : %s\n", b.jobinfo.companyName);
}