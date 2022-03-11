
#include <iostream>
#include <vector>

using namespace std;

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

int main() {

	vector<int> array = {4,3,2,10,12,1,5,6};

	insertionSort(array);


	return 0;
}