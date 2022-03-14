#include <iostream>
#include <algorithm>
using namespace std;

int elementoMayor_Indice(int array[], int sizeArray) {
    int mayor = -1;
    int indice = 0;

    for (int i = 0; i < sizeArray; i++) {
        if (array[i] > mayor) {
            mayor = array[i];
            indice = i;
        }
    }
    return indice;
}

int printe(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
}

int costo(int N, int M, int x[], int y[]) {

    if (N == 1 && M == 1)
        return 0;
    
    int mayorX = elementoMayor_Indice(x, N-1);
    int mayorY = elementoMayor_Indice(y, M-1);
    int coste1 = 0;
    int coste2 = 0;

    if (M <= 1 || x[mayorX] > y[mayorY]) {

        coste1 = costo(mayorX + 1, M, x, y);
        coste2 = costo(N - (mayorX + 1), M, x + (mayorX + 1), y);

        return coste1 + coste2 + x[mayorX];
    }
    else {
        coste1 = costo(N, mayorY + 1, x, y);
        coste2 = costo(N, M - (mayorY + 1), x, y + (mayorY + 1));

        return coste1 + coste2 + y[mayorY];
    }
}


int main() {

    int x[] = {1,2,100,4,5,6,7,8,9};

    int mayorX = elementoMayor_Indice(x, 9);

    printe(x, mayorX + 1);
    cout << endl;
    printe(x + (mayorX + 1), 9 - (mayorX + 1));

    return 0;
}