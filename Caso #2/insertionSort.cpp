#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


void generarArray(vector<int> &array, int n) {
	for (int i = 0; i < n; i++) {
		array.push_back(rand() % 200 + 1);
	}
}

void generarArrayMC(vector<int> &array, int n) {
	for (int i = 0; i < n; i++) {
		array.push_back(i);
	}
}
void generarArrayPC(vector<int> &array, int n) {
	for (int i = 0; i < n; i++) {
		array.push_back(n - i);
	}
}
void mostrarArray(vector<int> array) {
	cout << "[";
	for (int e : array) {
		cout << e << ", ";
	}
	cout << "]";
}



void insertionSort(vector<int> &array) {

	int arraySize = array.size();

	if (arraySize > 1) {

		int pointer1 = 0;
		int pointer2 = 1;
		int aux1 = pointer1;
		int aux2 = pointer2;

		while(pointer2 < arraySize) {

			if (aux1 >= 0 && array[aux1] > array[aux2]) {
				int saveKey = array[aux1];
				array[aux1] = array[aux2];
				array[aux2] = saveKey;
				
				aux1--;
				aux2--;
				continue;
			}
			pointer1++;
			pointer2++;
			aux1 = pointer1;
			aux2 = pointer2;
		}
	}
}

void startInsertionSort() {
	unsigned t0;
	unsigned t1;
	double time;

	vector<int> array1;
	vector<int> array2;
	vector<double> tiempos;
	vector<int> tamanos;

	// Caso lineal con Omega
	for (int i = 5000000; i <= 50000000; i += 5000000) {
		
		generarArrayMC(array1, i);

		t0 = clock();
		insertionSort(array1);
		t1 = clock();
		time = (double(t1 - t0)/CLOCKS_PER_SEC);

		tiempos.push_back(time);
		tamanos.push_back(i);
	
		array1.clear();
	}

	cout << "\n\t >>> CASO LINEAL:";
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
	cout << "\n >> Exp: La diferencia de tiempos crece de manera lineal, la diferencia de tiempos se mantiene muy parecida\nDif. Tiempos: ";
    for (int i = 1; i < tiempos.size(); i++) {
        cout << tiempos[i] - tiempos[i - 1] << ", ";
    }
    cout << endl;

	tiempos.clear();
	tamanos.clear();

	// Caso cuadratica con O-grande
	for (int i = 5000; i <= 50000; i += 5000) {
		
		generarArrayPC(array2, i);

		t0 = clock();
		insertionSort(array2);
		t1 = clock();
		time = (double(t1 - t0)/CLOCKS_PER_SEC);

		tiempos.push_back(time);
		tamanos.push_back(i);
	
		array2.clear();
	}

	cout << "\n\t >>> CASO CUADRATICO:";
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
	cout << "\n >> Exp: La diferencia de tiempos crece de manera cuadratica, la diferencia aumenta mucho en comparacion con la anterior\nDif. Tiempos: ";
    for (int i = 1; i < tiempos.size(); i++) {
        cout << tiempos[i] - tiempos[i - 1] << ", ";
    }
    cout << endl;
}

int main() {

	


	return 0;
}