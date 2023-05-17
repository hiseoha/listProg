#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

void init_list(ListType* L)
{
	L->size = 0;
}

int is_empty(ListType* L)
{
	return L->size == 0;
}

int is_full(ListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("Position Error");
	return L->array[pos];
}

void print_list(ListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d ¡æ ", L->array[i]);
	printf("\n\n");
}

void insert_last(ListType* L, element item)
{
	if (is_full(L)) {
		error("List is full\n");
	}
	L->array[L->size++] = item;
}

void insert(ListType* L, int pos, element item)
{
	int move = 0;
	if ((pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			move++;
		}
		L->array[pos] = item;
		L->size++;
	}
		printf("\nMove: %d\n\n", move);
}

element delete(ListType* L, int pos)
{
	element item;
	int move = 0;
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
		move++;
	}
	L->size--;

	printf("\nMove: %d", move);
	printf("\nDelete: %d\n\n", item);

	return item;
}

int main(void)
{	
	ListType L;
	init_list(&L);

	int choice, num, pos;


	while (1) {
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			if (is_full(&L)) {
				error("List is full\n");
			}
			else {
				printf("Enter the number and position: ");
				scanf_s("%d %d", &num, &pos);
				if (pos < 0 || pos > L.size) {
					printf("List size is zero. Please enter again.(number position): ");
					scanf_s("%d %d", &num, &pos);
				}
				insert(&L, pos, num);
			}
		}
		else if (choice == 2) {
			if (is_empty(&L)) {
				error("List is empty\n");
			}
			else {
				printf("Enter the position: ");
				scanf_s("%d", &pos);
				if (pos < 0 || pos > L.size) {
					printf("Position Error. Please enter the position again.: ");
					scanf_s("%d", &pos);
				}
				delete(&L, pos);
			}
		}
		else if (choice == 3) {
			if (is_empty(&L)) {
				error("List is empty\n");
			}
			else {
				print_list(&L);
			}
		}
		else if (choice == 0) {
			printf("Exit the program.\n");
			break;
		}
		else {
			printf("Invalid Menu. Please select again.\n\n");
		}
	}

	return 0;
}




