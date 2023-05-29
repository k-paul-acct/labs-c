#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define _CRT_SECURE_NO_WARNINGS
#define STR_LEN 256

typedef struct book {
    char author_surname[STR_LEN];
    char book_name[STR_LEN];
    char publisher[STR_LEN];
    int year;
} book;

typedef struct list_node {
    book* value;
    struct list_node* next;
} list_node;

void create_file_command(FILE** file, list_node* root);
void print_file_command(list_node* root);
void books_number_by_name_command(list_node* root);
void book_by_number_command(list_node* root);
void change_book_year_by_number_command(list_node* root);
void save_to_file_command(FILE* file, list_node* root);

int create_file(FILE** file);
int load_file(FILE* file, list_node* root);
int books_number_by_name(list_node* root, char* name);
book* read_book();
list_node* add_node(list_node* prev_node);

int read_int();
size_t getline(char** lineptr, size_t* n, FILE* stream);

void print_menu();
void choose_file();
void print_book(book* book);
void print_book_with_tabs(book* book);

int main() {
    list_node root = {0};
    FILE* file = fopen("FB.txt", "r");

    if (file != NULL) load_file(file, &root);

    while (1) {
        print_menu();
        int option = read_int();

        switch (option) {
            case 1:
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                if (file == NULL) {
                    choose_file();
                    continue;
                }
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

        switch (option) {
            case 1:
                create_file_command(&file, &root);
                break;
            case 2:
                print_file_command(&root);
                break;
            case 3:
                books_number_by_name_command(&root);
                break;
            case 4:
                book_by_number_command(&root);
                break;
            case 5:
                change_book_year_by_number_command(&root);
                break;
            case 6:
                save_to_file_command(file, &root);
                return 0;
            default:
                break;
        }
    }
}

void print_menu() {
    printf("Choose an option:\n");
    printf("\t1. Create a file.\n");
    printf("\t2. Print a file.\n");
    printf("\t3. Books number by name.\n");
    printf("\t4. Book by number.\n");
    printf("\t5. Change book year by number.\n");
    printf("\t6. Save and exit.\n");
}

void choose_file() { printf("Create file, please.\n"); }

int create_file(FILE** file) {
    *file = fopen("FB.txt", "w");
    if (file == NULL) return 0;
    return 1;
}

void create_file_command(FILE** file, list_node* root) {
    create_file(file);
    printf("Enter a number of books: ");
    int n = read_int();

    for (int i = 0; i < n; ++i) {
        root->value = read_book();
        if (i < n - 1) root = add_node(root);
    }
}

void print_file_command(list_node* root) {
    for (int number = 1; root != NULL; root = root->next, ++number) {
        printf("Book %d:\n", number);
        print_book_with_tabs(root->value);
    }
}

void books_number_by_name_command(list_node* root) {
    char* line = NULL;
    size_t n;
    size_t size;

    printf("Enter book name: ");
    size = getline(&line, &n, stdin);
    line[size - 1] = '\0';

    int number = books_number_by_name(root, line);
    printf("Result: %d\n", number);

    free(line);
}

void book_by_number_command(list_node* root) {
    printf("Enter book number: ");
    int n = read_int();
    if (n <= 0) {
        printf("Incorrect number.\n");
        return;
    }

    for (; root != NULL; root = root->next, --n) {
        if (n == 1) {
            print_book(root->value);
            break;
        }
    }
}

void change_book_year_by_number_command(list_node* root) {
    printf("Enter book number: ");
    int n = read_int();
    if (n <= 0) {
        printf("Incorrect number.\n");
        return;
    }

    printf("Enter new year value: ");
    int year = read_int();
    if (year <= 0) {
        printf("Incorrect year.\n");
        return;
    }

    for (; root != NULL; root = root->next, --n) {
        if (n == 1) {
            root->value->year = year;
            printf("Year changed.\n");
            break;
        }
    }
}

void save_to_file_command(FILE* file, list_node* root) {
    for (; root != NULL; root = root->next) {
        fwrite(root->value, sizeof(book), 1, file);
    }
}

int load_file(FILE* file, list_node* root) {
    book curr_book;
    list_node* prev_node = NULL;

    while (fread(&curr_book, sizeof(book), 1, file) == 1) {
        book* b = malloc(sizeof(book));
        memcpy(b, &curr_book, sizeof(book));
        root->value = b;

        if (prev_node != NULL) prev_node->next = root;

        prev_node = root;
        root = malloc(sizeof(list_node));
        root->next = NULL;
    }

    return 0;
}

void print_book(book* book) {
    printf("Author: %s\n", book->author_surname);
    printf("Book name: %s\n", book->book_name);
    printf("Publisher: %s\n", book->publisher);
    printf("Year: %d\n", book->year);
}

void print_book_with_tabs(book* book) {
    printf("\tAuthor: %s\n", book->author_surname);
    printf("\tBook name: %s\n", book->book_name);
    printf("\tPublisher: %s\n", book->publisher);
    printf("\tYear: %d\n", book->year);
}

int books_number_by_name(list_node* root, char* name) {
    int counter = 0;

    for (; root != NULL; root = root->next) {
        if (strcmp(root->value->book_name, name) == 0) ++counter;
    }

    return counter;
}

book* read_book() {
    size_t size;
    int year;
    book* b = malloc(sizeof(book));

    printf("Author surname: ");
    fgets(b->author_surname, STR_LEN, stdin);
    size = strlen(b->author_surname);
    (b->author_surname)[size - 1] = '\0';

    printf("Book name: ");
    fgets(b->book_name, STR_LEN, stdin);
    size = strlen(b->book_name);
    (b->book_name)[size - 1] = '\0';

    printf("Publisher: ");
    fgets(b->publisher, STR_LEN, stdin);
    size = strlen(b->publisher);
    (b->publisher)[size - 1] = '\0';

    do {
        printf("Year: ");
        year = read_int();
        if (year <= 0) printf("Invalid year.\n");
    } while (year <= 0);

    b->year = year;

    return b;
}

list_node* add_node(list_node* prev_node) {
    list_node* node = malloc(sizeof(list_node));
    prev_node->next = node;
    node->next = NULL;
    return node;
}

int read_int() {
    int number;
    char* line = NULL;
    size_t n;
    size_t size;

    size = getline(&line, &n, stdin);
    line[size - 1] = '\0';
    number = atoi(line);

    free(line);

    return number;
}

size_t getline(char** lineptr, size_t* n, FILE* stream) {
    if (*lineptr == NULL) {
        *n = 256;
        *lineptr = malloc(256 * sizeof(char));
    }

    size_t index_to_write = 0;
    int c = EOF;

    while (c != '\n') {
        c = fgetc(stream);
        if (c == EOF) break;

        if (index_to_write >= *n - 1) {
            *n = *n * 2;
            *lineptr = realloc(*lineptr, *n * sizeof(char));
        }

        (*lineptr)[index_to_write++] = c;
    }

    (*lineptr)[index_to_write] = '\0';

    return index_to_write;
}