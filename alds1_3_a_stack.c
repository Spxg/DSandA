#include <stdio.h>
#include <stdlib.h>

const int STACK_SIZE = 100;

struct Stack {
    int len;
    int stack[STACK_SIZE];
    void (*push)(int);
    int (*pop)();
} stack;

void push(int value) {
    if (stack.len < STACK_SIZE) {
        stack.stack[stack.len] = value;
        stack.len += 1;
    }
}

int pop() {
    if (stack.len > 0) {
        stack.len -= 1;
        int value = stack.stack[stack.len];
        return value;
    } else {
        return -1;
    }
}

void insert_func() {
    stack.pop = pop;
    stack.push = push;
}

int main(int argc, char const *argv[]) {
    insert_func();
    char c;
    int a, b;

    while ( scanf("%c", &c) != EOF ) {
        if (c == '\n') { break; }

        switch (c) {
        case '*':
            a = stack.pop();
            b = stack.pop();
            stack.push(a * b);
            break;
        case '+':
            a = stack.pop();
            b = stack.pop();
            stack.push(a + b);
            break;
        case '-':
            a = stack.pop();
            b = stack.pop();
            stack.push(b - a);
            break;
        default:
            stack.push(atoi(&c));
            break;
        }
    }

    printf("%d\n", stack.pop());
    return 0;
}
