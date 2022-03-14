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

void printe(int array[], int n) {
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

    int x[] = {2, 7, 8};
    int y[] = {4, 3, 9};

    cout << costo(4, 4, x, y) << endl;

    return 0;
}
