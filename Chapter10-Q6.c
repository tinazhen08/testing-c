/* Some calculators (notably those from Hewlett-Packard) use a system of writing mathematical expressions known as Reverse Polish Notation (RPN). In this notation, operators are
placed after their operands instead of between their operands. For example, 1 +2 would be
written 1 2 + in RPN, and 1 + 2* 3 would be written 123* +. RPN expressions can easily
be evaluated using a stack. The algorithm involves reading the operators and operands in an
expression from left to right, performing the following actions:
When an operand is encountered, push it onto the stack.
When an operator is encountered, pop its operands from the stack, perform the operation on those operands, and then push the result onto the stack.
Write a program that evaluates RPN expressions. The operands will be single-digit integers.
The operators are +,-, *, /, and =. The = operator causes the top stack item to be displayed;
afterwards, the stack is cleared and the user is prompted to enter another expression. The
process continues until the user enters a character that is not an operator or operand:
Enter an RPN expression: 1 2 3 * + =
Value of expression: 7
Enter an RPN expression: 5 8 * 4 9- / =
Value of expression: -8
Enter an RPN expression: g
If the stack overflows, the program will display the message Expression is too complex and terminate. If the stack underflows (because of an expression such as 1 2++), the
program will display the message Not enough operands in expression and terminate. Hints: Incorporate the stack code from Section 10.2 into your program. Use
scanf(" %c", &ch) to read the operators and operands. */


#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
    top = 0;
}

int is_empty(void) {
    return top == 0;
}

int is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full()) {
        printf("Expression is too complex\n");
        exit(EXIT_FAILURE);
    }

    contents[top++] = i;
}

int pop(void) {
    if (is_empty()) {
        printf("Not enough operands in expression\n");
        exit(EXIT_FAILURE);
    }

    return contents[--top];
}

int main(void) {
    char ch;
    int operand1, operand2;

    for (;;) {
        make_empty();

        printf("Enter an RPN expression: ");

        while (scanf(" %c", &ch) == 1) {
            if (ch >= '0' && ch <= '9') {
                push(ch - '0');
            } else {
                switch (ch) {
                    case '+':
                        operand2 = pop();
                        operand1 = pop();
                        push(operand1 + operand2);
                        break;

                    case '-':
                        operand2 = pop();
                        operand1 = pop();
                        push(operand1 - operand2);
                        break;

                    case '*':
                        operand2 = pop();
                        operand1 = pop();
                        push(operand1 * operand2);
                        break;

                    case '/':
                        operand2 = pop();
                        operand1 = pop();

                        if (operand2 == 0) {
                            printf("Division by zero\n");
                            exit(EXIT_FAILURE);
                        }

                        push(operand1 / operand2);
                        break;

                    case '=':
                        printf("Value of expression: %d\n", pop());
                        make_empty();
                        goto next_expression;

                    default:
                        return 0;
                }
            }
        }

        return 0;

        next_expression:
        ;
    }
}
