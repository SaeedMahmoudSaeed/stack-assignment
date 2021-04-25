#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    int data;
    struct stackNode *nextPtr;
};
typedef struct stackNode stackNode;
typedef stackNode *stackNodePtr;
void push(stackNodePtr *topPtr, int info);
int pop(stackNodePtr *topPtr);
int isEmpty(stackNodePtr topPtr);
void printstack(stackNodePtr currentPtr);
void instructions(void);
int main(void)
{
    stackNodePtr stackPtr= NULL;
    int value;
    instructions();
    printf("%s","?");
    unsigned int choice;
    scanf("%u",&choice);
    while(choice!=3)
    {
        switch (choice)
        {
            case 1:
            printf("%s","Enter an integer:");
            scanf("%d",&value);
            push(&stackPtr,value);
            printstack(stackPtr);
            break;

            case 2:
            if(!isEmpty(stackPtr))
                {
                    printf("the popped value is %d.\n",pop(&stackPtr));
                }
            printstack(stackPtr);
            break;
            default:
                puts("Invalid choice.\n");
                instructions();
                break;
        }
        printf("%s","?");
        scanf("%u",&choice);
    }
    puts("End of run.");
    return 0;
}
void instructions(void)
{
    puts("Enter choice:\n"
         "1 to push a value on the stack\n"
         "2 to pop a value off the stack\n"
         "3 to end program");
}
void push(stackNodePtr *topPtr,int info)
{
    stackNodePtr newPtr=malloc(sizeof(stackNode));
    if(newPtr !=NULL)
    {
        newPtr->data=info;
        newPtr->nextPtr=*topPtr;
        *topPtr=newPtr;
    }
    else
    {
        printf("%d not inserted. No memory available.\n",info);
    }
}
int pop(stackNodePtr *topPtr)
{
    stackNodePtr tempPtr=*topPtr;
    int popValue=(*topPtr)->data;
    *topPtr=(*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}
void printstack(stackNodePtr currentPtr)
{
    if(currentPtr==NULL)
    {
        puts("the stack is empty.\n");
    }
    else
    {
        puts("the stack is :");
        while(currentPtr!=NULL)
        {
            printf("%d-->",currentPtr->data);
            currentPtr=currentPtr->nextPtr;
        }
        puts("Null\n");
    }
}
int isEmpty(stackNodePtr topPtr)
{
    return topPtr==NULL;
}
