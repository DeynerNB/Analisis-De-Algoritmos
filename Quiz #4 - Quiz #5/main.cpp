#include <iostream>
#include <algorithm>
using namespace std;

int elementoMayor_Indice(int array[], int sizeArray) {
    int mayor = -1;
    int indice = -1;

    for (int i = 0; i < sizeArray; i++) {
        if (array[i] > mayor) {
            mayor = array[i];
            indice = i;
        }
    }
    return indice;
}

// f(n) = 2f(n/2) + 41
// O(nlog2(n))
// (x1 + x2 + ... + xn) + (N * (y1 + y2 + ... + ym))

int costo(int N, int M, int x[], int y[]) {

    if (N == 1 && M == 1)
        return 0;

    int mayorX = elementoMayor_Indice(x, N-1);
    int mayorY = elementoMayor_Indice(y, M-1);
    int coste1 = 0;
    int coste2 = 0;

    if ((mayorY == -1) || ((mayorX >= 0 && mayorY >= 0) && (x[mayorX] > y[mayorY]))) {

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

    // int x[] = {2, 7, 8};
    // int y[] = {4, 3, 9};

    // int x[] = {2, 5, 5, 9, 12};
    // int y[] = {4, 3, 9};

    // int x[] = {2, 7, 8, 20};
    // int y[] = {4, 1, 3, 48, 10};

    int x[] = {2};
    int y[] = {4, 3, 9, 10};


    int x_Size = (sizeof(x)/sizeof(x[0])) + 1;
    int y_Size = (sizeof(y)/sizeof(y[0])) + 1;

    cout << "Coste minimo: ";
    cout << costo(x_Size, y_Size, x, y) << endl;

    return 0;
}
