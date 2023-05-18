#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

void insert_number(const char *str);

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);

    insert_number(str);

    return 0;
}

void insert_number(const char *str) {
    char temp[MAX_LENGTH];
    const char delim[] = " ";
    char *word;

    strcpy(temp, str);
    word = strtok(temp, delim);

    while (word != NULL) {
        int is_num = 1;
        int len = strlen(word);

        if (word[len - 1] == '\n') --len;

        if (len == 0) is_num = 0;

        for (int i = 0; i < len; ++i) {
            if (!isdigit(word[i])) {
                is_num = 0;
                break;
            }
        }

        if (is_num) printf("номер ");

        printf("%s ", word);
        word = strtok(NULL, delim);
    }
}