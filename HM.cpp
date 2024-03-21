#include <iostream>

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }
    void resize(int new_capacity) {
        int* temp = new int[new_capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = new_capacity;
    }
    void initialize(int initial_capacity) {
        delete[] arr;
        capacity = initial_capacity;
        size = 0;
        arr = new int[capacity];
    }
    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void clear() {
        delete[] arr;
        size = 0;
        capacity = 2;
        arr = new int[capacity];
    }

    void append(int element) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = element;
    }

    void insert(int index, int element) {
        if (index < 0 || index > size) {
            std::cerr << "Index out of bounds\n";
            return;
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds\n";
            return;
        }
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size < capacity / 2) {
            resize(capacity / 2);
        }
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray arr;
    arr.initialize(5);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.print();
    arr.insert(1, 10);
    arr.print();
    arr.remove(2);
    arr.print();

    return 0;
}



#include <iostream>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            count++;
        }
    }

    int* newArr = new int[count];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newArr[index++] = arr[i];
        }
    }

    newSize = count;
    return newArr;
}

int main() {
    int arr[] = { 2, 3, 5, 6, 8, 11, 13, 15 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int newSize;
    int* newArr = removePrimes(arr, size, newSize);

    std::cout << "Array after removing primes: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << newArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] newArr;

    return 0;
}



#include <iostream>

void distributeElements(int* staticArray, int size, int*& positiveArray, int& positiveSize, int*& negativeArray, int& negativeSize, int*& zeroArray, int& zeroSize) {
    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; ++i) {
        if (staticArray[i] > 0)
            positiveSize++;
        else if (staticArray[i] < 0)
            negativeSize++;
        else
            zeroSize++;
    }

    positiveArray = new int[positiveSize];
    negativeArray = new int[negativeSize];
    zeroArray = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (staticArray[i] > 0)
            positiveArray[posIndex++] = staticArray[i];
        else if (staticArray[i] < 0)
            negativeArray[negIndex++] = staticArray[i];
        else
            zeroArray[zeroIndex++] = staticArray[i];
    }
}

int main() {
    const int size = 10;
    int staticArray[size] = { 5, -3, 0, 8, -2, 0, -6, 4, 0, -9 };
    int* positiveArray;
    int positiveSize;
    int* negativeArray;
    int negativeSize;
    int* zeroArray;
    int zeroSize;

    distributeElements(staticArray, size, positiveArray, positiveSize, negativeArray, negativeSize, zeroArray, zeroSize);

    std::cout << "Positive elements: ";
    for (int i = 0; i < positiveSize; ++i) {
        std::cout << positiveArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Negative elements: ";
    for (int i = 0; i < negativeSize; ++i) {
        std::cout << negativeArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Zero elements: ";
    for (int i = 0; i < zeroSize; ++i) {
        std::cout << zeroArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] positiveArray;
    delete[] negativeArray;
    delete[] zeroArray;

    return 0;
}
