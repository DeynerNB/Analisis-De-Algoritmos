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


int main() {


    vector<int> vector1;
    vector<int> tamanos;
    vector<double> tiempos;

    unsigned t0;
    unsigned t1;
    double time;
    
    // Caso Logaritmico : Mejor Caso
    for (int i = 5000; i < 50000; i += 5000) {
        generarVectorMC(vector1, i);

        t0 = clock();
        quickSort(vector1, 0, vector1.size() - 1);
        t1 = clock();

        time = double(t1 - t0) / CLOCKS_PER_SEC;

        tiempos.push_back(time);
        tamanos.push_back(i);

        vector1.clear();
    }

    cout << "\t >>> CASO LOGARITMICO:\n";
	cout << "\n\n---------------------------------";
	cout << "\n Array Tamano: " << tamanos[0];
	cout << "\n Tiempo: " << tiempos[0];
	cout << "\n---------------------------------";

	for (int i = 1; i < tiempos.size(); i++) {
		cout << "\n\n---------------------------------";
		cout << "\n Array Tamano: " << tamanos[i];
		cout << "\n Tiempo: " << tiempos[i];
		cout << "\n Diferencia: " << (tiempos[i] - tiempos[i - 1]);
		cout << "\n---------------------------------";
	}

    return 0;
}