/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(){
    // Buat objek Stack
    Stack clues;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&clues);

    int n;
    int counter = 0;
    scanf("%d", &n);
    getchar();
    //int tempcount = 0;
    char tempstr[10];
    for(int i = 0; i < n; i++){
        char clue[20];
        // scanf("%[^\n]", clue);
        //gets(clue);
        //printf("%s", clue);
        //printf("bruh\n");
        //getline(cin, clue);
        scanf(" %s", clue);
        // if (strcmp(clue, "Clue") == 0){
        //     if(tempcount == 1){
        //         n++;
        //         tempcount = 0;
        //         continue;
        //     }
        //     stack_push(&clues, 1);
        //     counter++;
        // }
        // else if (strcmp(clue, "No") == 0){
        //     stack_push(&clues, 0);
        //     tempcount = 1;
        // }
        if (strcmp(clue, "Clue") == 0){
            stack_push(&clues, 1);
            counter++;
        }
        else if (strcmp(clue, "No") == 0){
            scanf(" %s", tempstr);
            stack_push(&clues, 0);
            
        }
    }
    int inputs;
    scanf("%d", &inputs);
    getchar();
    for (int i = 0; i < inputs; i++){
        char command[20];
        //getline(cin, command);
        //gets(command);
        //printf("%s\n", command);
        scanf(" %s", command);
        // if(strcmp(command, "them") == 0){
        //     inputs++;
        //     continue;
        // }
        // else if (strcmp(command, "Out") == 0){
        //     if(stack_top(&clues) == 1){
        //         printf("I'm going crazy, right?\n");
        //         counter--;
        //     }
        //     stack_pop(&clues);
        // }
        // else if (strcmp(command, "Count") == 0){
        //     if(stack_size(&clues) >= 5){
        //         printf("He's the one that's living in my system\n");
        //     }
        //     else{
        //         printf("They keep on asking me, \"Who is he?\"\n");
        //     }
        // }
        
        if (strcmp(command, "Out") == 0){
            if(stack_top(&clues) == 1){
                printf("I'm going crazy, right?\n");
                counter--;
            }
            stack_pop(&clues);
        }
        else if (strcmp(command, "Count") == 0){
            scanf(" %s", tempstr);
            if(counter >= 5){
                printf("He's the one that's living in my system\n");
            }
            else{
                printf("They keep on asking me, \"Who is he?\"\n");
            }
        }
    }

    // // Operasi pada stack
    // stack_push(&myStack, 1);
    // stack_push(&myStack, 2);
    // stack_push(&myStack, 3);

    // // cetak isi stack
    // while (!stack_isEmpty(&myStack)) {
    //     printf("%d ", stack_top(&myStack));
    //     stack_pop(&myStack);
    // }
    // puts("");
    return 0;
}