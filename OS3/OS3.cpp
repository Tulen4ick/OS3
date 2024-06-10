#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct list
{
	int id;
	int time;
    struct list* next;
};

struct list* add(struct list* head, int a, int t) {
	while ((head->next) != NULL) {
		head = head->next;
	}
	struct list* temp = (struct list*)malloc(sizeof(list*));
	head->next = temp;
	temp->id = a;
	temp->time = t;
	temp->next = NULL;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int n, i, t;
	struct list* head = NULL;
	printf("Введите количество процессов: \n");
	scanf("%d", &n);
	printf("Введите %d процессов: \n", n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &t);
		add(head, i, t);
	}
	printf("ID введенных процессов: ");
	struct list* p = head;
	while (p != NULL) {
		printf("%5d ", p->id);
		p = p->next;
	}
	printf("\nВремена обработки:      ");
	p = head;
	while (p != NULL) {
		printf("%5d ", p->time);
		p = p->next;
	}
}