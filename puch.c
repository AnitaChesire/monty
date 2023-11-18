#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    top++;
    stack[top] = value;
}

void pall() {
    int i;

    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    FILE *file = fopen("your_input_file.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char opcode[4];
    int value;
    int line_number = 0;

    while (fscanf(file, "%s", opcode) != EOF) {
        line_number++;

        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    return 0;
}

