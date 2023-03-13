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

// ----------------------------------------------------------------QUEUE

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

// ----------------------------------------------------------------STACK

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

int main()
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    // Buat objek QueueArray
    Queue myQueue;

    // PENTING! Jangan lupa diinisialisasi
    queue_init(&myQueue);

    int counter = 1;
    for(int i = 1; i != 0; ){
        int n;
        int tempcounter = 0;
        int count = 0;
        //int temparr[n]={0};
        scanf("%d", &n);
        int temparr[n];
        for(int j = 0; j < n; j++){
            int input;
            scanf("%d", &input);
            if (input == counter){
                queue_push(&myQueue, input);
                counter++;
            }
            else{
                stack_push(&myStack, input);
            }
        }
        while(!stack_isEmpty(&myStack)){
            int tempint = stack_top(&myStack);
            queue_push(&myQueue, tempint);
            stack_pop(&myStack);
        }
        while (!queue_isEmpty(&myQueue)) {
            //printf("%d ", queue_front(&myQueue));
            temparr[count] = queue_front(&myQueue);
            queue_pop(&myQueue);
            count++;
        }
        // for(int k = 0; k < n ; k++) {
        //     printf("%d ", temparr[k]);
        // }
        // printf("\n");
        for(int x = 0; x < n - 1 ; x++) {
            if (temparr[x] < temparr[x+1]) {
                tempcounter++;
            }
            //printf("%d ", tempcounter);
        }
        if(n == 0){
            break;
        }
        else if(tempcounter == n - 1){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        printf("\n");
        i = n;
        counter = 1;
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