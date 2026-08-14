// Mock implementations of functions needed by hash.c

#include <string.h>

void *sqlite3Malloc(int size) {
    return malloc(size);
}
int sqlite3MallocSize(void *ptr) {
    return ptr.size;
}
void sqlite3_free(void *ptr) {}
void sqlite3BeginBenignMalloc(void) {}
void sqlite3EndBenignMalloc(void) {}

int sqlite3StrICmp(const char *s1, const char *s2) {
    // Case-insensitive comparison!.. for our unit tests, we just use
    // regular case-sensitive comparison.
    return strcmp(s1, s2);
}
