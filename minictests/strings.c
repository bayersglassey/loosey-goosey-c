#include <stdio.h>
#include <string.h>


int clamp_cmp(int cmp) {
    // strcmp and strncmp are allowed to return arbitrary negative/positive
    // numbers, not just -1 and 1.
    // We want unit tests that work for gcc and loosey, so we clamp the
    // output to -1..1
    return cmp < 0? -1: cmp > 0? 1: 0;
}
#define STRCMP(X, Y) printf("strcmp(%s, %s) = %i\n", #X, #Y, clamp_cmp(strcmp(X, Y)));
#define STRNCMP(X, Y, N) printf("strncmp(%s, %s, %i) = %i\n", #X, #Y, N, clamp_cmp(strncmp(X, Y, N)));


const char *string_or_null(const char *s) {
    return s? s: "NULL";
}


int main() {

    printf("=== STRCMP:\n");
    STRCMP("", "")
    STRCMP("a", "")
    STRCMP("", "a")
    STRCMP("a", "a")
    STRCMP("abc", "abc")
    STRCMP("abz", "abc")
    STRCMP("abz", "abz")
    STRCMP("abcc", "abc")
    STRCMP("abc", "abcc")

    printf("=== STRNCMP:\n");
    STRNCMP("", "", 0)
    STRNCMP("", "", 1)
    STRNCMP("a", "", 0)
    STRNCMP("a", "", 1)
    STRNCMP("", "a", 0)
    STRNCMP("", "a", 1)
    STRNCMP("a", "a", 1)
    STRNCMP("abcc", "abc", 3)
    STRNCMP("abcc", "abc", 4)
    STRNCMP("abc", "abcc", 3)
    STRNCMP("abc", "abcc", 4)

    printf("=== STRLEN:\n");
    {
        char s[] = "hello\0*******";
        printf("%i\n", (int)strlen(s));
        printf("%i\n", (int)strnlen(s, 7));
        printf("%i\n", (int)strnlen(s, 3));
    }

    printf("=== STRCPY:\n");
    {
        char dst[] = "*********";
        char src1[] = "BBB";
        char src2[] = "CCC";
        strcpy(dst, src1);
        printf("%s\n", dst);
        strncpy(dst, src2, 2);
        printf("%s\n", dst);
    }

    printf("=== STRCAT:\n");
    {
        char dst[] = "AAA\0********";
        char src1[] = "BBB";
        char src2[] = "CCC";
        strcat(dst, src1);
        printf("%s\n", dst);
        strncat(dst, src2, 2);
        printf("%s\n", dst);
    }

    printf("=== STRDUP:\n");
    {
        char s[] = "hello\0****";
        char *s2 = strdup(s);
        char *s3 = strndup(s, 7);
        char *s4 = strndup(s, 3);
        printf("%s\n", s2);
        printf("%s\n", s3);
        printf("%s\n", s4);
    }

    printf("=== STR{CHR,STR}:\n");
    {
        char s[] = "hello";
        printf("%s\n", string_or_null(strchr(s, 'l')));
        printf("%s\n", string_or_null(strchr(s, 'x')));
        printf("%s\n", string_or_null(strstr(s, "ll")));
        printf("%s\n", string_or_null(strstr(s, "ack")));
    }

    return 0;
}
