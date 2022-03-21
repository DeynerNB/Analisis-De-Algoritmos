#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// 0 Estatico - 1 Aleatorio
#define PIVOT_TYPE 0

void generarVectorMC(vector<int>& a, int n) {
    for (int i = 0; i < n; i++)
        a.push_back(i);
}
void generarVectorPC(vector<int>& a, int n) {
    for (int i = 0; i < n; i++)
        a.push_back(n - i);
}
void generarVector(vector<int>& a, int n) {
    for (int i = 0; i < n; i++)
        a.push_back(rand() % 200 + 1);
}
void intercambiar(vector<int>& a, int index1, int index2) {
    int aux = a[index1];
    a[index1] = a[index2];
    a[index2] = aux;
}
int particionar(vector<int>& a, int imin, int imax) {

    // Mover pivote al final
    if (imin)
        intercambiar(a, imin + (imax - imin - 1), imax);
    else
        intercambiar(a, (imax + 1)/2, imax);

    int j = imin;
    int k = imin;
    int ind_Pivote = imax;

    while (j < ind_Pivote) {
        
        if (a[j] < a[ind_Pivote]) {
            intercambiar(a, j, k);
            k++;
        }
        j++;
    }
    
    intercambiar(a, k, ind_Pivote);
    return k;
}
void quickSort(vector<int>& a, int imin, int imax) {

    if (imax <= imin)
        return;

    int k = particionar(a, imin, imax);

    quickSort(a, imin, k-1);
    quickSort(a, k+1, imax);
}
void startQuickSort() {
    vector<int> vector1;
    vector<int> tamanos;
    vector<double> tiempos;

    unsigned t0;
    unsigned t1;
    double time;
    
    // Caso Logaritmico : Mejor Caso
    for (int i = 5000; i <= 50000; i += 5000) {
        generarVectorMC(vector1, i);

        t0 = clock();
        quickSort(vector1, 0, vector1.size() - 1);
        t1 = clock();

        time = double(t1 - t0) / CLOCKS_PER_SEC;

        tiempos.push_back(time);
        tamanos.push_back(i);

        vector1.clear();
    }

    cout << "\t >>> CASO LOGARITMICO:";
    cout << "\n---------------------------------";
    cout << "\n Array Tamano: " << tamanos[0];
    cout << "\n Tiempo: " << tiempos[0];
    cout << "\n---------------------------------";

    for (int i = 1; i < tiempos.size(); i++) {
        cout << "\n\n---------------------------------";
        cout << "\n Array Tamano: " << tamanos[i];
        cout << "\n Tiempo: " << tiempos[i];
        cout << "\n Diferencia: " << (tiempos[i] - tiempos[i - 1]);
        cout << "\n Proporcion: " << (tiempos[i - 1] / tiempos[i]);
        cout << "\n---------------------------------";
    }
    cout << "\n >> Exp: La diferencia de tiempos crece de manera logaritmica, no hay tanta diferencia entre el tiempo anterior y el actual\nDif. Tiempos: ";
    for (int i = 1; i < tiempos.size(); i++) {
        cout << tiempos[i] - tiempos[i - 1] << ", ";
    }
    cout << endl;

    tamanos.clear();
    tiempos.clear();

    // Caso Cuadratico : Peor Caso
    for (int i = 5000; i <= 50000; i += 5000) {
        generarVectorPC(vector1, i);

        t0 = clock();
        quickSort(vector1, 0, vector1.size() - 1);
        t1 = clock();

        time = double(t1 - t0) / CLOCKS_PER_SEC;

        tiempos.push_back(time);
        tamanos.push_back(i);

        vector1.clear();
    }

    cout << "\n\n\t >>> CASO CUADRATICO:";
    cout << "\n---------------------------------";
    cout << "\n Array Tamano: " << tamanos[0];
    cout << "\n Tiempo: " << tiempos[0];
    cout << "\n---------------------------------";

    for (int i = 1; i < tiempos.size(); i++) {
        cout << "\n\n---------------------------------";
        cout << "\n Array Tamano: " << tamanos[i];
        cout << "\n Tiempo: " << tiempos[i];
        cout << "\n Diferencia: " << (tiempos[i] - tiempos[i - 1]);
        cout << "\n Proporcion: " << (tiempos[i - 1] / tiempos[i]);
        cout << "\n---------------------------------";
    }
    cout << "\n >> Exp: La diferencia de tiempos crece de manera exponencial, en este caso, las diferencias son mayores al caso anterior\nDif. Tiempos: ";
    for (int i = 1; i < tiempos.size(); i++) {
        cout << tiempos[i] - tiempos[i - 1] << ", ";
    }
    cout << endl;
}



int main() {
    


    return 0;
}