#include <iostream>
#include <vector>

using namespace std;

// 0 Estatico - 1 Aleatorio
#define PIVOT_TYPE 0

int ANALISIS_intercambios;
int ANALISIS_operaciones;
int ANALISIS_asignaciones;
int ANALISIS_comparaciones;
int ANALISIS_llamadas;
int ANALISIS_retornos;

bool firstPivot = true;

int getPivot(vector<int> array, int n) {
    if (PIVOT_TYPE)
        return array[rand() % n];
    else
        return array[n - 1];
}
void generarArray(vector<int> &array, int n) {
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % 200 + 1);
    }
}
void reiniciarContadores() {
    ANALISIS_intercambios = 0;
    ANALISIS_operaciones = 0;
    ANALISIS_asignaciones = 0;
    ANALISIS_comparaciones = 0;
    ANALISIS_llamadas = 0;
    ANALISIS_retornos = 0;
    firstPivot = true;
}
void mostrarArray(vector<int> array) {
    cout << "[";
    for (int e : array) {
        cout << e << ", ";
    }
    cout << "]";
}


vector<int> QuickSort(vector<int>& array) {

    int arraySize = array.size();
    ANALISIS_asignaciones++;
    ANALISIS_llamadas++;

    ANALISIS_comparaciones++;
    if (arraySize > 1) {

        int pivot = getPivot(array, arraySize);
        ANALISIS_asignaciones++;
        ANALISIS_llamadas+=3;

        if (firstPivot) {
            cout << "\nPivote Inicial: " << pivot;
            firstPivot = false;
        }

        vector<int> leftSide;
        vector<int> rightSide;

        ANALISIS_asignaciones++;
        for (auto elem = array.begin(); elem != array.end(); ++elem) {
            ANALISIS_comparaciones++;
            ANALISIS_asignaciones++;
            ANALISIS_operaciones += 1;

            ANALISIS_comparaciones++;
            ANALISIS_llamadas+=2;
            if (*elem > pivot)
                rightSide.push_back(*elem);
            else if(*elem < pivot)
                leftSide.push_back(*elem);
        }

        ANALISIS_asignaciones += 2;
        ANALISIS_llamadas += 2;
        leftSide = QuickSort(leftSide);
        rightSide = QuickSort(rightSide);

        ANALISIS_llamadas += 2;
        leftSide.push_back(pivot);

        ANALISIS_llamadas += 7;
        leftSide.insert(leftSide.end(), rightSide.begin(), rightSide.end());

        ANALISIS_asignaciones++;
        array = leftSide;
    }

    ANALISIS_retornos++;
    return array;
}

int main() {

    vector<int> arrayS_1 = {77, 75, 23, 43, 55, 12, 64, 44};
    vector<int> arrayS_2 = {10, 20, 30, 40, 50, 60, 70, 80};
    vector<int> arrayS_3 = {80, 70, 60, 50, 40, 30, 20, 10};

    if (PIVOT_TYPE)
        cout << " >> Pivote Aleatorio\n";
    else
        cout << " >> Pivote Fijo\n";

    reiniciarContadores();
    cout << "---------------------------------\n";
    cout << "Array Original: "; mostrarArray(arrayS_1);
    arrayS_1 = QuickSort(arrayS_1);
    cout << "\nArray Tamano: " << arrayS_1.size();
    cout << "\nIntercambio: " << ANALISIS_intercambios;
    cout << "\nOperaciones: " << ANALISIS_operaciones;
    cout << "\nAsignaciones: " << ANALISIS_asignaciones;
    cout << "\nComparaciones: " << ANALISIS_comparaciones;
    cout << "\nLlamadas: " << ANALISIS_llamadas;
    cout << "\nRetornos: " << ANALISIS_retornos;
    cout << "\nArray Ordenado: "; mostrarArray(arrayS_1);
    cout << "\n---------------------------------\n\n";

    reiniciarContadores();
    cout << "---------------------------------\n";
    cout << "Array Original: "; mostrarArray(arrayS_2);
    arrayS_2 = QuickSort(arrayS_2);
    cout << "\nArray Tamano: " << arrayS_2.size();
    cout << "\nIntercambio: " << ANALISIS_intercambios;
    cout << "\nOperaciones: " << ANALISIS_operaciones;
    cout << "\nAsignaciones: " << ANALISIS_asignaciones;
    cout << "\nComparaciones: " << ANALISIS_comparaciones;
    cout << "\nLlamadas: " << ANALISIS_llamadas;
    cout << "\nRetornos: " << ANALISIS_retornos;
    cout << "\nArray Ordenado: "; mostrarArray(arrayS_2);
    cout << "\n---------------------------------\n\n";

    reiniciarContadores();
    cout << "---------------------------------\n";
    cout << "Array Original: "; mostrarArray(arrayS_3);
    arrayS_3 = QuickSort(arrayS_3);
    cout << "\nArray Tamano: " << arrayS_3.size();
    cout << "\nIntercambio: " << ANALISIS_intercambios;
    cout << "\nOperaciones: " << ANALISIS_operaciones;
    cout << "\nAsignaciones: " << ANALISIS_asignaciones;
    cout << "\nComparaciones: " << ANALISIS_comparaciones;
    cout << "\nLlamadas: " << ANALISIS_llamadas;
    cout << "\nRetornos: " << ANALISIS_retornos;
    cout << "\nArray Ordenado: "; mostrarArray(arrayS_3);
    cout << "\n---------------------------------\n\n";




    return 0;
}