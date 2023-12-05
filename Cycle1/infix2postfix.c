#include <stdio.h>
#include <ctype.h>

char a[50], b[50];

int op(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}

void check(char a[], char b[]) {
    char s[50];
    int i = 0, j = 0, top = -1;

    while (a[i] != '\0') {
        if (isalnum(a[i])) {
            b[j++] = a[i];
            i++;
        } else if (a[i] == '(') {
            s[++top] = a[i];
            i++;
        } else if (a[i] == ')') {
            while (top != -1 && s[top] != '(') {
                b[j++] = s[top--];
            }
            if (top != -1 && s[top] == '(') {
                top--;  // Pop the '(' from the stack
            }
            i++;
        } else {
            while (top != -1 && op(a[i]) <= op(s[top])) {
                b[j++] = s[top--];
            }
            s[++top] = a[i];
            i++;
        }
    }

    while (top != -1) {
        b[j++] = s[top--];
    }

    b[j] = '\0';
}

int main() {
    printf("<-character->");
    scanf("%s", a);
    check(a, b);
    printf("%s\n", b);
    return 0;
}
