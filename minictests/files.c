#include <stdio.h>
#include <errno.h>

const char *errname() {
    switch (errno) {
        case ENOENT: return "ENOENT";
        case EBADF: return "EBADF";
        default: return "<UNKNOWN>";
    }
}

FILE *open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file) printf("Failed to open: %s (errno=%s)\n", filename, errname());
    return file;
}

void write_string(FILE *file, const char *s) {
    if (fprintf(file, "%s\n", s) < 0) printf("Failed to write \"%s\" (errno=%s)\n", s, errname());
}

void read_string(char *buf, int size, FILE *file) {
    char *s = fgets(buf, size, file);
    if (!s) printf("Failed to read up to %i bytes from file (errno=%s)\n", size, errname());
}

int main() {
    {
        FILE *f1;
        f1 = open_file(".test.txt", "w");
        write_string(f1, "Hello!");
        fclose(f1);
    }
    {
        FILE *f2;
        char buf[10];
        f2 = open_file("doesnt-exist.txt", "r");
        f2 = open_file(".test.txt", "r");
        read_string(buf, 7, f2);
        printf("Read: \"%s\"\n", buf);
        fclose(f2);
    }
    return 0;
}
