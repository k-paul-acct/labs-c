#include <stdio.h>
#include <string.h>

const char* my_strchr(const char* s, int c);

int main() {
    char str1[] = "qwerty";
    char str2[] = "123";

    printf("my_strchr '%s', 'r': %p\n", str1, my_strchr(str1, 'r'));
    printf("strchr    '%s', 'r': %p\n\n", str1, strchr(str1, 'r'));

    printf("my_strchr '%s', '4': %p\n", str2, my_strchr(str1, '4'));
    printf("strchr    '%s', '4': %p\n", str2, strchr(str1, '4'));

    return 0;
}

const char* my_strchr(const char* s, int c) {
    while (*s != c && *s != '\0') s++;
    if (*s != c) return NULL;
    return s;
}