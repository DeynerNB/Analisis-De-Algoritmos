#include <iostream>
#include <vector>
using namespace std;

void printe(vector<int> &array) {
    for(auto i : array)
        cout << i << ", ";
    cout << endl;
}

void QuickSort(vector<int> &array) {
    int sizeArray = array.size();

    if (sizeArray > 1) {
        int pivotePosition = sizeArray / 2;

        int left = 0;
        int right = sizeArray - 2;
        int pivote = array[pivotePosition];

        int aux = array[sizeArray - 1];
        array[sizeArray - 1] = pivote;
        array[pivotePosition] = aux;

        while(true) {

            while (array[left] < pivote)
                left++;

            while (array[right] > pivote)
                right--;

            if (left < right) {
                aux = array[left];
                array[left] = array[right];
                array[right] = aux;
            }
            else
                break;
        }

        aux = array[left];
        array[left] = pivote;
        array[sizeArray - 1] = aux;

        vector<int> leftSide(array.begin(), (array.begin() + left));
        vector<int> rightSide((array.begin() + left + 1), array.end());

        printe(leftSide);
        printe(rightSide);

        QuickSort(leftSide);
        QuickSort(rightSide);
    }
}


int main() {
    vector<int> V = {1,3,6,4,2,5,7,8};

    //QuickSort(V);



    return 0;
}