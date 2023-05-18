#include <stdio.h>
#include <string.h>

char *my_strncat(char *dest, const char *src, size_t n);

int main() {
    char str1[50] = "Hello, ";
    char str2[] = "world!";
    char str3[50] = "Hello, ";
    char str4[] = "world!";
    size_t n = 3;

    printf("my_strncat '%s', '%s', %zu: %s\n", str1, str2, n, my_strncat(str1, str2, n));
    printf("strncat    '%s', '%s', %zu: %s\n", str3, str4, n, strncat(str3, str4, n));

    return 0;
}

char *my_strncat(char *dest, const char *src, size_t n) {
    char *ptr = dest;
    while (*ptr) ptr++;
    while (*src && n--) *ptr++ = *src++;
    *ptr = '\0';
    return dest;
}