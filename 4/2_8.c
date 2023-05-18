#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

void print_longest(char *s);

int main() {
    char str[MAX_LENGTH] = "So, we'll go no more a roving so late into the night";

    printf("String:\n%s\n", str);
    print_longest(str);

    return 0;
}

void print_longest(char *s) {
    char *word;
    char delim[] = " ";
    char temp[MAX_LENGTH] = "";
    int max_len = 0;

    word = strtok(s, delim);

    while (word != NULL) {
        int len = strlen(word);

        if (len > max_len) {
            max_len = len;
            strncpy(temp, word, len);
        }

        word = strtok(NULL, delim);
    }

    printf("Longest word:\n%s\n", temp);
}