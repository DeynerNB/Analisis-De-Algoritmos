#include <iostream>
#include <vector>

using namespace std;


vector<int> QuickSort_StaticPivot(vector<int> array) {
    if (array.size() > 1) {

        int pivot = array[array.size() - 1];

        vector<int> leftSide;
        vector<int> rightSide;

        for (auto elem = array.begin(); elem != (array.end() - 1); ++elem) {
            if (*elem > pivot)
                rightSide.push_back(*elem);
            else
                leftSide.push_back(*elem);
        }

        leftSide = QuickSort_StaticPivot(leftSide);
        rightSide = QuickSort_StaticPivot(rightSide);

        leftSide.push_back(pivot);

        leftSide.insert(leftSide.end(), rightSide.begin(), rightSide.end());
        array = leftSide;
    }
    return array;
}
vector<int> QuickSort_RandomPivot(vector<int> array) {
    if (array.size() > 1) {

        int pivotPosition = rand() % array.size();
        int pivot = array[pivotPosition];

        vector<int> leftSide;
        vector<int> rightSide;

        for (int i = 0; i < array.size(); i++) {
            if (i != pivotPosition) {
                if (array[i] > pivot)
                    rightSide.push_back(array[i]);
                else
                    leftSide.push_back(array[i]);
            }
        }

        leftSide = QuickSort_RandomPivot(leftSide);
        rightSide = QuickSort_RandomPivot(rightSide);

        leftSide.push_back(pivot);

        leftSide.insert(leftSide.end(), rightSide.begin(), rightSide.end());
        array = leftSide;
    }
    return array;
}

int main() {

    V = QuickSort_StaticPivot(V);

    return 0;
}