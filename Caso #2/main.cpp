#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <time.h>
using namespace std;

// *******************************
// ***** Algoritmo Free Text *****
// *******************************
map<string, int> prefixPatternMap;

void initPrefixPatternMap(string pattern) {
    
    int patternLenght = pattern.length();

    for (int i = 0; i < (patternLenght - 1); i++) {
        prefixPatternMap.insert(make_pair(pattern.substr(0, i+1), i));
    }
}
int getCharIndex(string pattern, char letter, int sizePattern) {
    int index = -1;

    for (int i = 0; i < sizePattern; i++)
        if (pattern[i] == letter)
            return i;

    return index;
}
int Boyer_Moore_BadChar(string text, string pattern, int pointerPattern, int pointerText, int shiftPattern) {
    int badChar_Index = getCharIndex(pattern, text[pointerText], pointerPattern);

    if (badChar_Index != -1) {
        return shiftPattern + (pointerPattern - badChar_Index);
    }
    else {
        return shiftPattern + pointerPattern + 1;
    }
}
int Boyer_Moore_GoodSufx(string text, string pattern, int pointerPattern, int pointerText, int shiftPattern) {  

    if (shiftPattern <= 1) {
        return shiftPattern;
    }
    else {
        string subStringText = text.substr((pointerText + 1), shiftPattern);
        string subPattern;

        // Check for sufix inside the pattern
        for (int i = 0; i <= pointerPattern; i++) {
            subPattern = pattern.substr((pointerPattern - i), shiftPattern);
            if (subPattern == subStringText)
                return shiftPattern + (i + 1);
        }

        // Check for sufix of sufix in prefix of pattern
        while(subStringText.length() > 1) {
            subStringText.erase(0, 1);
            if (prefixPatternMap.find(subStringText) != prefixPatternMap.end())
                return shiftPattern + pointerPattern + 1;
        }

        return -1;
    }
}
int Boyer_Moore_Text(string text, string pattern) {
    if (pattern.length() > text.length())
        return 0;

    initPrefixPatternMap(pattern);

    int pointerPattern = pattern.length() - 1;
    int pointerText = pointerPattern;
    int shiftPattern = 0;
    int matches = 0;

    while(pointerText < text.length()) {
        if (text[pointerText] == pattern[pointerPattern]) {
            pointerPattern--;
            pointerText--;
            shiftPattern++;

            if (pointerPattern < 0) {
                matches++;
                
                pointerPattern += shiftPattern;
                pointerText += (shiftPattern + pattern.length());

                shiftPattern = 0;
            }
        }
        else {

            int numShift = max(
                Boyer_Moore_BadChar(text, pattern, pointerPattern, pointerText, shiftPattern),
                Boyer_Moore_GoodSufx(text, pattern, pointerPattern, pointerText, shiftPattern)
            );

            pointerPattern += shiftPattern;
            pointerText += numShift;

            shiftPattern = 0;
        }
    }

    return matches;
}
void readFile(string *text) {
    ifstream file("text.txt");

    cout << "Abriendo archivo...\n";
    if (file.is_open()) {

        cout << "Leyendo archivo...\n";
        while(!file.eof()) {
            getline(file, *text);
        }

        cout << "Archivo leido por completo!\n";
    }
    else {
        cout << "Fallo al intentar abrir el archivo!!!\n" << endl;
    }

    file.close();
}
void startFreeText() {
    string text;
    string pattern;
    int result = 0;
    unsigned t0, t1;

    // Get user input pattern
    cin.ignore();
    cout << "\nIngrese el patron a buscar: ";
    getline(cin, pattern);

    readFile(&text);

    // Change pattern into lower case
    for (int i = 0; i < pattern.length(); i++)
        pattern[i] = tolower(pattern[i]);

    // Change file text into lower case
    cout << "\nConversion del archivo a minusculas iniciado...\n";
    t0 = clock();
    for (int i = 0; i < text.length(); i++)
        text[i] = tolower(text[i]);
    t1 = clock();
    cout << "Conversion del archivo a minusculas finalizado\n";
    cout << "Tiempo de la conversion: " << double(t1 - t0)/CLOCKS_PER_SEC << endl;

    int limitSize = text.length()/2000;
    string subText;

    cout << "\nProcesamiento freetext del archivo iniciado...\n";
    t0 = clock();
    for (int i = 0; i < text.length(); i += limitSize) {
        subText = text.substr(i, limitSize);

        while (text[i + limitSize] != ' ' && text[i + limitSize] != '\0') {
            subText += text[i + limitSize];
            i++;
        }

        result += Boyer_Moore_Text(subText, pattern);
    }
    t1 = clock();
    cout << "Procesamiento freetext del archivo finalizado!\n";
    cout << "Tiempo del procesamiento: " << double(t1 - t0)/CLOCKS_PER_SEC << endl;


    cout << "\nTotal de apariciones de '" << pattern << "': " << result << endl;
}
// *******************************


// *******************************
// *** Algoritmo InsertionSort ***
// *******************************
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

    cout << "\nTiempo de espera aproximado: 10seg caso lineal / 1min caso exponencial\n";

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
// *******************************



// *******************************
// ***** Algoritmo Quicksort *****
// *******************************
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

    cout << "\nTiempo de espera aproximado: 15seg caso logaritmico / 45seg caso exponencial\n";
    
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
// *******************************

int main() {
    
    char option;

    do {
        cout << "\n\nSeleccione una opcion:\n";
        cout << "1) Iniciar quickSort:\n";
        cout << "2) Iniciar insertionSort:\n";
        cout << "3) Iniciar freeText:\n";
        cout << "S) Salir:\n";
        cout << "**IMPORTANTE: El archivo txt para el freeText debe estar en la misma carpeta del main y con nombre 'text.txt'\n";
        cout << "-->: ";
        cin >> option;

        switch(option) {
            case '1':
                startQuickSort();
                break;
            case '2':
                startInsertionSort();
                break;
            case '3':
                startFreeText();
                break;
        }

    } while(toupper(option) != 'S');

    return 0;
}