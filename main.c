#include "monty.h"

int main()
{
    stack_t *stack = NULL;

    char opcode[4];
    int value;

    while (scanf("%3s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (scanf("%d", &value) != 1)
            {
                fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
                exit(EXIT_FAILURE);
            }
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(stack);
        }
        else
        {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", __LINE__, opcode);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
