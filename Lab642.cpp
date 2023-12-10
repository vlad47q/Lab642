#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void inputArray(int* arr, int arrLength, int index = 0) {

    if (index == arrLength) {
        return;
    }

    cout << "arr[" << index << "] = "; cin >> arr[index];

    inputArray(arr, arrLength, index + 1);
}

void printArray(int* arr, int arrLength, int index = 0) {

    if (index == arrLength) {
        cout << endl;
        return;
    }

    cout << setw(5) << arr[index];
    printArray(arr, arrLength, index + 1);
}

int countOfElemsGreaterThan(int* arr, int size, int C, int index = 0, int counter = 0) {

    if (index == size) {
        return counter;
    }

    if (arr[index] > C) {
        counter++;
    }
    countOfElemsGreaterThan(arr, size, C, index + 1, counter);
}

int findMaxAbsIndex(int* arr, int size, int index = 0, int maxAbs = 0, int maxAbsIndex = 0){
    if (index == size) {
        return maxAbsIndex;
    }
    if (abs(arr[index]) > maxAbs) {
        maxAbs = abs(arr[index]);
        maxAbsIndex = index;
    }
    findMaxAbsIndex(arr, size, index + 1, maxAbs, maxAbsIndex);
}

int findElementsMultiplier(int* arr, int size, int index, int mtpr = 1) {
    if (index + 1 == size) {
        return mtpr;
    }
    if (index + 1 != size) {
        mtpr *= arr[index + 1];
    }
    findElementsMultiplier(arr, size, index + 1, mtpr);
}

int findAmountOfNegative(int* arr, int size, int index = 0, int amnt = 0) {
    if (index == size) {
        return amnt;
    }
    
    if (arr[index] < 0) {
        amnt++;
    }
    findAmountOfNegative(arr, size, index + 1, amnt);
}

void fakeSortArr(int* arr, int* arrCopy, int size, int positiveIndex, int index = 0, int negativeIndex = 0) {
    if (index == size) {
        return;
    }

    if (arr[index] < 0) {
        arrCopy[negativeIndex] = arr[index];
        negativeIndex++;
    }
    else {
        arrCopy[positiveIndex] = arr[index];
        positiveIndex++;
    }
    fakeSortArr(arr, arrCopy, size, positiveIndex, index + 1, negativeIndex );

}


int main() {
    int size, c;
    cout << "input size: "; cin >> size;
    cout << "input C: "; cin >> c;

    int* dynamicArray = new int[size];

    inputArray(dynamicArray, size);
    printArray(dynamicArray, size);

    cout << "Count of elems greater than " << c << " is: " << countOfElemsGreaterThan(dynamicArray, size, c) << endl;
    cout << "Multiplier of elements that goes after the element that has a highest abs in the array = " << findElementsMultiplier(dynamicArray, size, findMaxAbsIndex(dynamicArray, size)) << endl;

    int* fsArray = new int[size];
    
    fakeSortArr(dynamicArray, fsArray, size, findAmountOfNegative(dynamicArray, size));

    cout << "Old array: " << endl;
    printArray(dynamicArray, size);

    cout << "Fakesorted array: " << endl;
    printArray(fsArray, size);

    return 0;
}