#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX_STACK;
}


bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}


bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}


void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP:";
    for (int i = S.Top; i >= 1; i--) {
        cout << " " << S.info[i];
    }
    cout << endl;
}


void balikStack(Stack &S) {
    Stack Bantu;
    createStack(Bantu);

    int n = S.Top;
    int v, tmp;

    for (int tetap = 0; tetap < n - 1; tetap++) {
        int m = n - tetap;         
        pop(S, v);                  
        for (int i = 0; i < m - 1; i++) {
            pop(S, tmp);
            push(Bantu, tmp);
        }
        push(S, v);                 
        while (!isEmpty(Bantu)) {
            pop(Bantu, tmp);
            push(S, tmp);
        }
    }
}