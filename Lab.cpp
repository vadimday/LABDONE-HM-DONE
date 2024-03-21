#include <iostream>

void sumAndProduct(int* array, int size, int* sum, int* product) {
    *sum = 0;
    *product = 1;

    for (int i = 0; i < size; ++i) {
        *sum += array[i];
        *product *= array[i];
    }
}

int main() {
    const int size = 5;
    int array[size] = { 1, 2, 3, 4, 5 };
    int sum, product;

    sumAndProduct(array, size, &sum, &product);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}


#include <iostream>

void countElements(int* array, int size, int& numPositive, int& numNegative, int& numZero) {
    numPositive = 0;
    numNegative = 0;
    numZero = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] > 0)
            numPositive++;
        else if (array[i] < 0)
            numNegative++;
        else
            numZero++;
    }
}

int main() {
    const int size = 7;
    int array[size] = { 5, -3, 0, 8, -2, 0, -6 };
    int numPositive, numNegative, numZero;

    countElements(array, size, numPositive, numNegative, numZero);

    std::cout << "Number of positive elements: " << numPositive << std::endl;
    std::cout << "Number of negative elements: " << numNegative << std::endl;
    std::cout << "Number of zero elements: " << numZero << std::endl;

    return 0;
}



#include <iostream>

int* isSubset(int* A, int sizeA, int* B, int sizeB) {
    for (int i = 0; i <= sizeA - sizeB; ++i) {
        bool found = true;
        for (int j = 0; j < sizeB; ++j) {
            if (A[i + j] != B[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return &A[i];
        }
    }
    return nullptr;
}

int main() {
    const int sizeA = 10;
    const int sizeB = 3;
    int A[sizeA] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int B[sizeB] = { 3, 4, 5 };

    int* result = isSubset(A, sizeA, B, sizeB);

    if (result != nullptr) {
        std::cout << "found: " << result - A << std::endl;
    }
    else {
        std::cout << "not" << std::endl;
    }

    return 0;
}


#include <iostream>

int* removeNegativeNumbers(int* array, int& size) {
    int negativeCount = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0)
            negativeCount++;
    }
    int* newArray = new int[size - negativeCount];
    int newIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] >= 0)
            newArray[newIndex++] = array[i];
    }

    size -= negativeCount;

    delete[] array;

    return newArray;
}

int main() {
    int size = 5;
    int* dynamicArray = new int[size] {1, -2, 3, -4, 5};

    std::cout << "Original: ";
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    dynamicArray = removeNegativeNumbers(dynamicArray, size);

    std::cout << "neggative: ";
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] dynamicArray;

    return 0;
}



#include <iostream>
#include <cstring> 
void addBlockToEnd(int*& array, int& currentSize, int* elementsToAdd, int blockSize) {
    int newSize = currentSize + blockSize;
    int* newArray = new int[newSize];
    memcpy(newArray, array, currentSize * sizeof(int));
    memcpy(newArray + currentSize, elementsToAdd, blockSize * sizeof(int));
    delete[] array;
    array = newArray;
    currentSize = newSize;
}

int main() {
    int* array = new int[5] {1, 2, 3, 4, 5};
    int currentSize = 5;

    int elementsToAdd[] = { 6, 7, 8 };

    std::cout << "Original array: ";
    for (int i = 0; i < currentSize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    addBlockToEnd(array, currentSize, elementsToAdd, sizeof(elementsToAdd) / sizeof(int));

    std::cout << "Array after adding elements: ";
    for (int i = 0; i < currentSize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}
