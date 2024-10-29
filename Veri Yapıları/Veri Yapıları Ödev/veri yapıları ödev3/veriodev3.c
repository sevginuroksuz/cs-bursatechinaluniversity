#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    char data[16];
    struct node *link;
} NODE;

typedef struct queue {
    NODE *front;
    NODE *rear;
    int count;
} QUEUE;

QUEUE* CreateQueue() {
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

void Enqueue(QUEUE *q, char *dataIn) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    strcpy(newNode->data, dataIn);
    newNode->link = NULL;
    if (q->front == NULL)
        q->front = newNode;
    else
        q->rear->link = newNode;
    q->rear = newNode;
    q->count++;
}

void Dequeue(QUEUE *q, char *dataOut) {
    NODE *temp = q->front;
    strcpy(dataOut, q->front->data);
    if (q->count == 1)
        q->rear = NULL;
    q->front = q->front->link;
    q->count--;
    free(temp);
}

int QueueCount(QUEUE *q) {
    return q->count;
}

void Display(QUEUE *q) {
    NODE *pLoc = q->front;
    printf("\nexpression: ");
    while (pLoc != NULL) {
        printf("%s ", pLoc->data);
        pLoc = pLoc->link;
    }
    printf("\n");
}

void DestroyQueue(QUEUE *q) {
    NODE *temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
    free(q);
}

int calculate(char opr, int op1, int op2) {
    switch (opr) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return -1;
    }
}

int calculateExpression(QUEUE *q) {
    char data[16], data1[16], data2[16];
    int operand1, operand2, value;

    while (QueueCount(q) > 1) {
        Dequeue(q, data);
        char temp_opr = data[0];

        if (ispunct(temp_opr)) {  // İşlem operatörüyse
            strcpy(data1, q->front->data);
            strcpy(data2, q->front->link->data);

            if (!ispunct(data1[0]) && !ispunct(data2[0])) {
                operand1 = atoi(data1);
                operand2 = atoi(data2);

                Dequeue(q, data1);
                Dequeue(q, data2);

                value = calculate(temp_opr, operand1, operand2);
                sprintf(data, "%d", value);

                Enqueue(q, data);
                Display(q);
            } else {
                Enqueue(q, data);
                Display(q);
            }
        } else {
            Enqueue(q, data);
            Display(q);
        }
    }

    Dequeue(q, data);
    return atoi(data);
}

int main() {
    char expr[128];
    char *token;
    int finalvalue;

    printf("\nEnter the prefix string (e.g., '+ 3 5'):");
    fgets(expr, sizeof(expr), stdin);

    QUEUE *q = CreateQueue();
    token = strtok(expr, " ");
    while (token) {
        Enqueue(q, token);
        token = strtok(NULL, " ");
    }

    finalvalue = calculateExpression(q);
    printf("\n\nValue of the expression: %d\n", finalvalue);

    DestroyQueue(q);
    return 0;
}
