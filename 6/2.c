#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20
#define NUM_ELEMENTS 10

typedef struct node {
    char value[MAX_LEN];
    struct node* next;
} node;

void print_list(node* root);
void remove_after(node* root, int index);
void add_elem(node* root, char* value);

int main() {
    node* root = malloc(sizeof(node));
    root->next = NULL;
    node* curr = root;

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        sprintf(curr->value, "This is %d elem", i + 1);

        if (i < NUM_ELEMENTS - 1) {
            node* next = malloc(sizeof(node));
            next->next = NULL;
            curr->next = next;
            curr = next;
        }
    }

    print_list(root);

    remove_after(root, 5);

    printf("\nList after removing after 6:\n");
    print_list(root);

    add_elem(root, "This is 5 elem");

    printf("\nList after adding 'This is 5 elem':\n");
    print_list(root);
}

void print_list(node* root) {
    printf("List contents:\n");
    for (; root != NULL; root = root->next) printf("%s\n", root->value);
}

void remove_after(node* root, int index) {
    for (int i = 0; root != NULL; root = root->next, ++i) {
        if (i < index) continue;
        root->next = NULL;
        break;
    }
}

void add_elem(node* root, char* value) {
    for (; root->next != NULL; root = root->next) {
    }

    node* new = malloc(sizeof(node));
    new->next = NULL;
    strcpy(new->value, value);
    root->next = new;
}