#include <stdio.h>
#include <stdbool.h>


#define STACK_SIZE 1024
int _stack[STACK_SIZE], *stack=_stack;

void push(int x) {
    *stack = x;
    stack++;
}

int pop(void) {
    return *(--stack);
}

void print_stack(void) {
    int *p;
    fputs("Stack: ", stdout);
    for (p = _stack; p < stack; p += 1) {
        if (p != _stack) fputc(' ', stdout);
        printf("%i", *p);
    }
    fputc('\n', stdout);
}

int main() {
    int i = 0;
    bool building_i = false;
    bool newline = true;
    while (1) {
        char c;
        if (newline) {
            fputs("> ", stdout);
            newline = false;
        }
        fflush(stdout);
        c = getchar();
        if (c >= '0' && c <= '9') {
            i = i * 10 + (c - '0');
            building_i = true;
            continue;
        }
        switch (c) {
            case '\n':
                newline = true;
                // Fall through to next case
            case ' ': {
                if (building_i) {
                    push(i);
                    i = 0;
                    building_i = false;
                }
            } break;
            case '+': push(pop() + pop()); break;
            case '-': push(pop() - pop()); break;
            case '*': push(pop() * pop()); break;
            case 'n': *stack = -*stack; break;
            case 'd': /* drop */ pop(); break;
            case 'c': /* clear */ stack = _stack; break;
            case 'q': return 0;
            default: {
                fprintf(stderr, "Unexpected character: '%c'\n", c);
                return 1;
            }
        }
        if (newline) print_stack();
    }
}
