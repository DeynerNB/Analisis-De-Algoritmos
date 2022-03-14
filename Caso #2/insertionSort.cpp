
#include <iostream>
#include <vector>

using namespace std;

int ANALISIS_intercambios;
int ANALISIS_operaciones;
int ANALISIS_asignaciones;
int ANALISIS_comparaciones;

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

void reiniciarContadores() {
	ANALISIS_intercambios = 0;
	ANALISIS_operaciones = 0;
	ANALISIS_asignaciones = 0;
	ANALISIS_comparaciones = 0;
}

void insertionSort(vector<int> &array) {

	int arraySize = array.size();
	ANALISIS_asignaciones++;

	ANALISIS_comparaciones++;
	if (arraySize > 1) {

		int pointer1 = 0;
		int pointer2 = 1;
		int aux1 = pointer1;
		int aux2 = pointer2;
		ANALISIS_asignaciones += 4;

		while(pointer2 < arraySize) {
			ANALISIS_comparaciones++;

			ANALISIS_comparaciones += 3;
			ANALISIS_operaciones += 2;
			if (aux1 >= 0 && array[aux1] > array[aux2]) {

				int saveKey = array[aux1];
				array[aux1] = array[aux2];
				array[aux2] = saveKey;
				ANALISIS_asignaciones += 3;
				ANALISIS_operaciones += 4;
				ANALISIS_intercambios += 2;
				
				aux1--;
				aux2--;
				ANALISIS_operaciones += 2;
				ANALISIS_asignaciones += 2;
				continue;
			}
			pointer1++;
			pointer2++;
			aux1 = pointer1;
			aux2 = pointer2;
			ANALISIS_asignaciones += 4;
			ANALISIS_operaciones += 2;
		}
	}
}

int main() {

	vector<int> array1;
	vector<int> array2;
	vector<int> array3;
	vector<int> array4;
	vector<int> array5;

	vector<int> arrayMC;
	vector<int> arrayPC;

	generarArray(array1, 10);
	generarArray(array2, 10);
	generarArray(array3, 10);
	generarArray(array4, 10);
	generarArray(array5, 10);

	generarArrayMC(arrayMC, 10);
	generarArrayPC(arrayPC, 10);


	reiniciarContadores();
	insertionSort(array1);
	cout << "---------------------------------";
	cout << "\nArray Tamano: " << array1.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	reiniciarContadores();
	insertionSort(array2);
	cout << "---------------------------------";
	cout << "\nArray Tamano: " << array2.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	reiniciarContadores();
	insertionSort(array3);
	cout << "---------------------------------";
	cout << "\nArray Tamano: " << array3.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	reiniciarContadores();
	insertionSort(array4);
	cout << "---------------------------------";
	cout << "\nArray Tamano: " << array4.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	reiniciarContadores();
	insertionSort(array5);
	cout << "---------------------------------";
	cout << "\nArray Tamano: " << array5.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	reiniciarContadores();
	cout << "---------------------------------\n";
	cout << "ArrayMC: ";	mostrarArray(arrayMC);
	insertionSort(arrayMC);
	cout << "\nArray Tamano: " << arrayMC.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	reiniciarContadores();
	cout << "---------------------------------\n";
	cout << "ArrayPC: ";	mostrarArray(arrayPC);
	insertionSort(arrayPC);
	cout << "\nArray Tamano: " << arrayPC.size();
	cout << "\nIntercambio: " << ANALISIS_intercambios;
	cout << "\nOperaciones: " << ANALISIS_operaciones;
	cout << "\nAsignaciones: " << ANALISIS_asignaciones;
	cout << "\nComparaciones: " << ANALISIS_comparaciones;
	cout << "\n---------------------------------\n\n";

	return 0;
}