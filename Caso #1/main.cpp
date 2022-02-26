#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

// ----------------------------------------------------------------
// Ejercicio 1: Compare Triplets
// ----------------------------------------------------------------
vector<int> compareTriplets_1(vector<int> a, vector<int> b) {
    
    vector<int> result = {0, 0};
    
    // Recorre el vector y suma los puntos a quien tenga una calificacion mayor
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i])
            result[0]++;
        else if (a[i] < b[i])
            result[1]++;
    }
    
    // Devuelve el vector del puntaje
    return result;
}
vector<int> compareTriplets_2(vector<int> a, vector<int> b) {
    
    // Vector para resultados {Pto Bob, Empate, Pto Alice}
    vector<int> result = {0, 0, 0};

    // Indices para seleccionar a quien sumar el punto
    int num1 = 1;
    int num2 = 1;
    int num3 = 1;

    /*
        Si Bob es mayor: num = 1 - 1 = 0;
        Si Alice es mayor:   num = 1 + 1 = 2;
    */
    if (a[0] != b[0])
        num1 += (a[0] - b[0])/abs(a[0] - b[0]);
    if (a[1] != b[1])
        num2 += (a[1] - b[1])/abs(a[1] - b[1]);
    if (a[2] != b[2])
        num3 += (a[2] - b[2])/abs(a[2] - b[2]);

    // Suma puntos a los indices correspondientes
    result[num1]++;
    result[num2]++;
    result[num3]++;

    // Retorna un vector con puntos de Alice y Bob
    return {result[2], result[0]};
}

// ----------------------------------------------------------------
// Ejercicio 2: Time Conversion
// ----------------------------------------------------------------
string timeConversion_1(string s) {
    
    // Almacenar el formato(A, P) y los caracteres de la hora
    char timeFormat = s[s.size() - 2];
    string hour = s.substr(0, 2);
    
    // Eliminar los dos ultimos caracteres(AM / PM)
    s = s.substr(0, (s.size() - 2));
    
    // Si es AM y la hora son 12, cambia los caracteres a 00 y devuelve la hora
    if (timeFormat == 'A') {
        if (hour == "12")
            s[0] = s[1] = '0';
        return s;
    }
    else {
        // Si es PM y la hora 12, devuelve la string
        if (hour == "12")
            return s;
        
        // Si no, aumenta en 12 la hora y la convierte de nuevo a string
        int hourValue = stoi(hour) + 12;
        string newHour = to_string(hourValue);
        
        s[0] = newHour[0];
        s[1] = newHour[1];
        
        return s;
    }
}

string timeConversion_2(string s) {
    
    // Arrays de todas las horas
    string updateTime[] = {"xx", "01", "02", "03", "04", "05", "06", "07",
                           "08", "09", "10", "11", "00", 
                           "13", "14", "15", "16", "17", "18", "19",
                           "20", "21", "22", "23"};
    
    // Obtiene el formato, la hora y elimina los 2 ultimos caracteres(AM / PM)
    char timeFormat = s[s.size() - 2];
    int hour = stoi(s.substr(0, 2));
    s = s.substr(0, s.size() - 2);

    // Si el PM y la hora 12, devuelve la string, si no, suma 12 a la hora(indice para obtener la hora)
    if (timeFormat == 'P') {
        if (hour == 12)
            return s;
        hour += 12;
    }
    
    // Sustituye los caracteres con la nueva hora
    s[0] = updateTime[hour][0];
    s[1] = updateTime[hour][1];
    
    return s;
}

// ----------------------------------------------------------------
// Ejercicio 3: Birthday
// ----------------------------------------------------------------
int birthday_1(vector<int> s, int d, int m) {

    int sum = 0;
    int result = 0;

    // Ciclo anindado para recorrer el arreglo 2 veces, comparando todos los elementos con todos
    for (int i = 0; i <= (s.size() - m); i++) {
        sum = 0;
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }

        // Verifica si la suma cumple con la condicion para aumentar el result
        if (sum == d)
            result++;
    }
    return result;
}

int birthday_2(vector<int> s, int d, int m) {

    int result = 0;     // Cantidad de resultados
    int sum = 0;        // Variable para la suma
    int pointer = 0;    // Puntero para recorrer el array
    int m_aux = 0;      // Selecciona los adyacentes al puntero
    
    while (pointer < s.size()) {

        // Si tiene el tamano buscado, aumenta la suma        
        if (m_aux != m) {
            sum += s[pointer + (m_aux++)];
            continue;
        }
        pointer++;                      // Avanza el puntero
        result += (sum == d) ? 1 : 0;   // Si la suma es igual a la que busca, suma 1 al puntaje
        m_aux = sum = 0;                // Reinicia la suma y el m_aux
    }
    
    return result;
}

// ----------------------------------------------------------------
// Ejercicio 4: Minion Game
// ----------------------------------------------------------------
char vowels[] = {'A','E','I','O','U'};

bool isVowels(char letter) {
    for (char v : vowels)
        if (v == letter)
            return true;
    return false;
}

void minion_game(string word) {
    
    //{Stuart, Kevin}
    int points[] = {0, 0};
    int selector = 0;

    int wordLenght = 1;
    int pointer = 0;
    string subWord;

    while (wordLenght <= word.length()) {

        if (pointer >= word.length()) {
            pointer = 0;
            wordLenght++;
            continue;
        }

        subWord = word.substr(pointer, wordLenght);
        selector = (isVowels(word[pointer])) ? 1 : 0;
        
        if (subWord.length() == wordLenght)
            points[selector]++;

        pointer++;
    }

    if (points[0] > points[1])
        cout << "Stuart " << points[0] << endl;
    else if (points[0] < points[1])
        cout << "Kevin " << points[1] << endl;
    else
        cout << "Draw" << endl;

}

// ----------------------------------------------------------------
// Ejercicio 6: Pairs
// ----------------------------------------------------------------
int pairs_with_pointers(int k, vector<int> arr) {
    
    // Ordenar el array(ascendente)
    sort(arr.begin(), arr.end());
    
    // {Pointer 2, NULL, Pointer1}
    int pointers[] = {1, 0, 0};
    int result = 0;
    int valueDif = 0;
    
    while (pointers[0] < arr.size()) {
        
        valueDif = arr[pointers[0]] - arr[pointers[2]];
        
        // Si es lo que busco, aumento pointer2
        if (valueDif == k) {
            result++;
            pointers[0]++;
            continue;
        }
        
        // Mueve el puntero necesario dependiendo si es mayor o menor
        pointers[ ((valueDif - k)/abs(valueDif - k)) + 1 ]++;
    }
    
    return result;
}



int main() {

    vector<int> A_result1 = compareTriplets_1({20, 28, 50}, {50, 60, 70});
    vector<int> A_result2 = compareTriplets_1({17, 28, 30}, {99, 16, 8});
    vector<int> A_result3 = compareTriplets_1({5, 6, 7}, {3, 6, 10});

    cout << "\t> TRIPLETES\nSolucion con ciclo for:\n";
    cout << "\nTriplete 1:\n20   28   50\n50   60   70\n > {" <<
    A_result1[0] << ", " << A_result1[1] << "}\n";

    cout << "\nTriplete 2:\n17   28   30\n99   16   8\n > {" <<
    A_result2[0] << ", " << A_result2[1] << "}\n";

    cout << "\nTriplete 3:\n5   6   7\n3   6   10\n > {" <<
    A_result3[0] << ", " << A_result3[1] << "}\n";


    vector<int> result1 = compareTriplets_2({20, 28, 50}, {50, 60, 70});
    vector<int> result2 = compareTriplets_2({17, 28, 30}, {99, 16, 8});
    vector<int> result3 = compareTriplets_2({5, 6, 7}, {3, 6, 10});

    cout << "\nSolucion con manejo de indices:\n";
    cout << "\nTriplete 1:\n20   28   50\n50   60   70\n > {" <<
    result1[0] << ", " << result1[1] << "}\n";

    cout << "\nTriplete 2:\n17   28   30\n99   16   8\n > {" <<
    result2[0] << ", " << result2[1] << "}\n";

    cout << "\nTriplete 3:\n5   6   7\n3   6   10\n > {" <<
    result3[0] << ", " << result3[1] << "}\n";


    // ----------------------------------------------------------------

    cout << "\n\n\t> TIME CONVERSION\nTime conversion 1:";
    cout << "\nHora 12: 07:05:45PM -> Hora 24: " << timeConversion_2("07:05:45PM");
    cout << "\nHora 12: 12:40:22AM -> Hora 24: " << timeConversion_2("12:40:22AM");
    cout << "\nHora 12: 06:40:03AM -> Hora 24: " << timeConversion_2("06:40:03AM");

    cout << "\n\nTime conversion con array de las horas:";
    cout << "\nHora 12: 07:05:45PM -> Hora 24: " << timeConversion_2("07:05:45PM");
    cout << "\nHora 12: 12:40:22AM -> Hora 24: " << timeConversion_2("12:40:22AM");
    cout << "\nHora 12: 06:40:03AM -> Hora 24: " << timeConversion_2("06:40:03AM");

    // ----------------------------------------------------------------

    cout << "\n\n\t> BIRTHDAY\nSolucion 1: Birthday";
    cout << "\nResultado1 {1, 2, 1, 3, 2}: " << birthday_2({1, 2, 1, 3, 2}, 3, 2);
    cout << "\nResultado2 {2, 5, 1, 3, 4, 4, 3, 5, 1, 1, 2, 1, 4, 1, 3, 3, 4, 2, 1}: " << birthday_2({2, 5, 1, 3, 4, 4, 3, 5, 1, 1, 2, 1, 4, 1, 3, 3, 4, 2, 1}, 3, 2);
    cout << "\nResultado3 {5, 5, 3, 2, 2, 2, 1, 2, 5, 3, 5, 5, 4, 3, 3, 5}: " << birthday_2({5, 5, 3, 2, 2, 2, 1, 2, 5, 3, 5, 5, 4, 3, 3, 5}, 13, 3);

    cout << "\n\nSolucion 2: Birthday";
    cout << "\nResultado1 {1, 2, 1, 3, 2}: " << birthday_2({1, 2, 1, 3, 2}, 3, 2);
    cout << "\nResultado2 {2, 5, 1, 3, 4, 4, 3, 5, 1, 1, 2, 1, 4, 1, 3, 3, 4, 2, 1}: " << birthday_2({2, 5, 1, 3, 4, 4, 3, 5, 1, 1, 2, 1, 4, 1, 3, 3, 4, 2, 1}, 3, 2);
    cout << "\nResultado3 {5, 5, 3, 2, 2, 2, 1, 2, 5, 3, 5, 5, 4, 3, 3, 5}: " << birthday_2({5, 5, 3, 2, 2, 2, 1, 2, 5, 3, 5, 5, 4, 3, 3, 5}, 13, 3);

    // ----------------------------------------------------------------

    cout << "\n\n\t> MINION GAME\nPalabra: BANANA\n"; minion_game("BANANA");
    cout << "\nPalabra: EMPERATRIZ\n"; minion_game("EMPERATRIZ");
    cout << "\nPalabra: APARICION\n"; minion_game("APARICION");


    // ----------------------------------------------------------------

    vector<int> arr = {967551, 42711, 652888, 556131, 432461, 689084, 878716, 707516, 462627, 719131, 921983, 626364, 4162, 381455, 628368, 434733, 845482, 789342, 129922, 384203, 516975, 872544, 958157, 257969, 383516, 972027, 753530, 579132, 732314, 692990, 938898, 673695, 304274, 911598, 386363, 643777, 897942, 705604, 307205, 691832, 525153, 13560, 131633, 967903, 704917, 719007, 275998, 823133, 381356, 694812, 130946, 14247, 881464, 212321, 535615, 388113, 263786, 993408, 303132, 347246, 957012, 356253, 80278, 682192, 79591, 22168, 399471, 130259, 302213, 146877, 143512, 464001, 323710, 716383, 252562, 704230, 528752, 385676, 433835, 84087, 324397, 19622, 726853, 400158, 765711, 879403, 717070, 796189, 630429, 735240, 899316, 897255, 682879, 943532, 548896, 650909, 128885, 156561, 260454, 861309, 463314, 396080, 486644, 483429, 306518, 579819, 726166, 319856, 689771, 346559, 466803, 340669, 602785, 686432, 259959, 146736, 878107, 718444, 272951, 371357, 690458, 625990, 672321, 968982, 211634, 966184, 806955, 421135, 486063, 350431, 856525, 674382, 968295, 709010, 81652, 874036, 487437, 966921, 318376, 402219, 956325, 319682, 346722, 112336, 643090, 670617, 700593, 580506, 695051, 996996, 486750, 989387, 738565, 873231, 311817, 351118, 77220, 129572, 900003, 880777, 109146, 675069, 829732, 420069, 519779, 692670, 391266, 683566, 349744, 629055, 305831, 14934, 216260, 302900, 347933, 85417, 307892, 367031, 433148, 431774, 871170, 955638, 629386, 252687, 151756, 290426, 642403, 213008, 693677, 349307, 80965, 376767, 879481, 177826, 382142, 591034, 733001, 967608, 381793, 957699, 382829, 251634, 641716, 226476, 530957, 871857, 658236, 615467, 401532, 681505, 485376, 694364, 144675, 23169, 673008, 146049, 581193, 461940, 22324, 641029, 878794, 620846, 558429, 6994, 41576, 717757};
    vector<int> arr1 = {1, 3, 5, 8, 6, 4, 2};
    vector<int> arr2 = {1, 5, 3, 4, 2};


    cout << "\n\n\t> Pairs\nResultado: " << pairs_with_pointers(687, arr) << endl;
    cout << "Resultado {1, 3, 5, 8, 6, 4, 2}: " << pairs_with_pointers(2, arr1) << endl;
    cout << "Resultado {1, 5, 3, 4, 2}: " << pairs_with_pointers(2, arr2) << endl;

    return 0;
}
