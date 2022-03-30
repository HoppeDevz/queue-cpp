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

        cout << "Error:append-method -> Fila cheia!" << endl;
        return;
    }

    q->elements[q->finalValue] = number;
    q->finalValue++;
    q->totalElements++;

    if (q->finalValue == q->length) q->finalValue = 0;
}

void appendIni(queue q, int number) {

    if (q->totalElements >= q->length) {

        cout << "Error:append-method -> Filha cheia!" << endl;
        return;
    }

    int index = q->startValue - 1;

    if (index < 0)
        index = q->length - 1;

    q->elements[index] = number;
    q->startValue = index;
    q->totalElements++;
}

void removeItem(queue q) {

    if (q->totalElements == 0) {

        cout << "Error:removeItem -> Pilha Vazia!" << endl;
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

    if (q->totalElements == 0) {

        cout << "Error:showQeue -> Pilha Vazia!" << endl;
        return;
    }

    int counter = 0;

    for (int i = 0; i < q->totalElements; i++) {

        int index = q->startValue + i;

        if (q->startValue + i >= q->length) {

            index = 0 + counter;
            counter++;
        }

        cout << (int)q->elements[index] << " ";
    }
    cout << endl;
}

bool isFull(queue q) {

    return q->totalElements == q->length;
}

bool isEmpty(queue q) {
    
    return q->totalElements == 0;
}

int sumItems(queue q) {

    int sum = 0;

    if (q->totalElements == 0) {

        cout << "Error:sumItems -> Pilha Vazia!" << endl;
        return 0;
    }

    for (int i = 0; i < q->totalElements; i++) {

        int x = q->startValue + i == q->length ? 0 : q->startValue + i; 

        sum = sum + (int)q->elements[x];
    }

    return sum;
}