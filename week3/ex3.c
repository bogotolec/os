#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct linked_list {
	struct node *first;
};

void print_list(struct linked_list * list) {
	struct node *next = (*list).first;

	while (next != NULL){
		printf("%d\n", (*next).data);
		next = (*next).next;
	}
}

void insert_node(struct linked_list *list, int element, int index) {
	struct node *next = (*list).first;
	struct node *new = (struct node *) calloc(sizeof(struct node), 1);
	(*new).data = element;

	if (index == 0) {
		(*new).next = next;
		(*list).first = new;
	}

	else {
		struct node *current;
		for (int i = 0; i < index; ++i){
			current = next;
			next = (*current).next;
		}

		(*new).next = next;
		(*current).next = new;
	}
}

void delete_node(struct linked_list *list, int index) {
	struct node *next = (*list).first;

	if (index == 0) {
		(*list).first = (*next).next;
		free(next);
	}

	else {
		struct node *current;
		for (int i = 0; i < index; ++i) {
			current = next;
			next = (*next).next;
		}

		(*current).next = (*next).next;
		free(next);
	}

}

struct linked_list * create_list(){
	struct linked_list *list = calloc(sizeof(struct linked_list), 1);
	return list;
}

int main() {

	struct linked_list list = *create_list();
	insert_node(&list, 5, 0);
	insert_node(&list, 7, 1);
	insert_node(&list, 6, 1);
	insert_node(&list, 4, 0);

	delete_node(&list, 0);
	delete_node(&list, 2);
	print_list(&list);

	return 0;
}
