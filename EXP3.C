/*Implementations of Infix to Postfix Expression for real-world application.
*/
#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[50], postfix[50], c;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   priority(stack[top]) >= priority(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}