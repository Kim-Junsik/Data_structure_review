#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

typedef struct {
	int list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

void init(ArrayListType* L) {
	L->length = 0;
}
bool is_empty(ArrayListType* L) {
	return L->length == 0;
}
bool is_full(ArrayListType* L) {
	return L->length == MAX_LIST_SIZE;
}

void add_item(ArrayListType* L, int item) {
	if (is_full(L)) {
		printf("이미 배열이 가득찼습니다.\n");
		return;
	}
	int i = 0;
	for (i = 0; i < L->length; i++) {
		if (item < L->list[i]) {
			for (int j = L->length; j > i; j--)
				L->list[j] = L->list[j - 1];
			break;
		}
	}
	L->list[i] = item;
	L->length++;
}

void delete_item(ArrayListType* L, int item) {
	int i;
	for (i = 0; i < L->length; i++) {
		if (item == L->list[i]) {
			for (int j = i; j < L->length; j++) {
				L->list[j] = L->list[j + 1];
			}
		}
	}
	L->length--;
}

void clear_list(ArrayListType* L, int item) {
	L->length = 0;
}

bool is_in_list(ArrayListType* L, int item) {
	for (int i = 0; i < L->length; i++)
		if (L->list[i] == item)
			return true;
	return false;
}

int get_length(ArrayListType* L) {
	return L->length;
}

void display(ArrayListType* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->list[i]);
	printf("\n");
}