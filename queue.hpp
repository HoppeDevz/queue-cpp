#pragma once
#include "iostream"

using namespace std;

typedef char queueElement;

typedef struct Queue {

    int startValue;
    int finalValue;

    int totalElements;
    int length;

    queueElement* elements;

} *queue;

// | a | b | c | d |
// 
// startV = 0;
// endV = 1;
// total = 1;

queue createQueue(int length) {

    queue f = new struct Queue();

    f->length = length;

    f->totalElements = 0;
    f->startValue = 0;
    f->finalValue = 0;

    f->elements = new queueElement[length];

    return f;
}

void append(queue q, int number) {

    if (q->totalElements >= q->length) {

        cout << "Fila cheia!" << endl;
        return;
    }

    q->elements[q->finalValue] = number;
    q->finalValue++;
    q->totalElements++;

    if (q->finalValue == q->length) q->finalValue = 0;
}

void removeItem(queue q) {

    if (q->totalElements == 0) {

        cout << "Pilha Vazia!";
        return;
    }

    q->elements[q->startValue] = 0;

    if (q->startValue == q->length - 1) {

        q->startValue = 0;
        q->totalElements--;
        return;
    }

    q->startValue++;
    q->totalElements--;
}

void showQeue(queue q) {

    for (int i = 0; i < q->totalElements; i++) {

        int x = q->startValue + i == q->length ? 0 : q->startValue + i; 

        cout << (int)q->elements[x] << " ";
    }
    cout << endl;
}

bool isFull(queue q) {

    return q->totalElements == q->length;
}

bool isEmpty(queue q) {
    
    return q->totalElements == 0;
}
