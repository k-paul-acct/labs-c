#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20
#define NUM_ELEMENTS 10

typedef struct {
    char identifier[MAX_LEN];
} list_element;

typedef struct {
    list_element elements[NUM_ELEMENTS];
    int numElements;
} list;

void print_list(list *list);
void remove_elems(list *list, int k);
void add_elem(list *list, char *newIdentifier);

int main() {
    list list;
    list.numElements = NUM_ELEMENTS;

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        list_element element;
        sprintf(element.identifier, "This is %d elem", i + 1);
        list.elements[i] = element;
    }

    print_list(&list);

    remove_elems(&list, 7);

    printf("\nList after removing after 6:\n");
    print_list(&list);

    add_elem(&list, "This is 5 elem");

    printf("\nList after adding 'This is 5 elem':\n");
    print_list(&list);

    return 0;
}

void print_list(list *list) {
    printf("List contents:\n");
    for (int i = 0; i < list->numElements; i++) {
        printf("%s\n", list->elements[i].identifier);
    }
}

void remove_elems(list *list, int k) {
    for (int i = 0; i < list->numElements; ++i) {
        if (i + 1 < k) continue;

        list->numElements = i;
        break;
    }
}

void add_elem(list *list, char *newIdentifier) {
    list_element newElement;
    strcpy(newElement.identifier, newIdentifier);
    list->elements[list->numElements++] = newElement;
}