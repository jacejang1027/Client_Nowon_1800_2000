#include <stdio.h>
#include <stdlib.h>

void AddFirst(int, int), AddLast(int, int), ShowAll();


typedef struct _Node {
	int id;
	int value;
	struct _Node* next;
} Node;

Node* head, * tail, * tmp, * tmp2;

void AddLast(int in_id, int in_value) {
	tmp = (Node*)malloc(sizeof(Node));
	if (head == NULL)
		head = tmp;
	else
		tail->next = tmp;

	tmp->id = in_id;
	tmp->value = in_value;
	tmp->next = NULL;
	tail = tmp;
}

void AddFirst(int in_id, int in_value) {
	tmp = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		head = tmp;
		tail = head;
	}
	else
		tmp->next = head;

	tmp->id = in_id;
	tmp->value = in_value;
	head = tmp;
}

void AddAfter(int target_id, int in_id, int in_value) {
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->id == target_id) {
			tmp2 = (Node*)malloc(sizeof(Node));

			tmp2->next = tmp->next;
			tmp->next = tmp2;
			tmp2->id = in_id;
			tmp2->value = in_value;
			return;
		}
		tmp = tmp->next;
	}
	return;
}


void ShowAll() {
	tmp = head;
	printf("(id, value) : ");
	while (tmp != NULL)
	{
		printf("(%d, %d)", tmp->id, tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {

	AddLast(1, 3);
	AddLast(3, 25);
	AddLast(6, 35);
	AddLast(21, 4);
	AddAfter(21, 33, 33);
	ShowAll();

	return 0;
}