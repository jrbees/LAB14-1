#include <iostream>

using namespace std;

double average(double* a, int size) {
    if (size == 0)
        return 0.0;

    double sum = 0.0;
    double* p = a;

    for (int i = 0; i < size; ++i) {
        sum += *p;
        p++;
    }

    return sum / size;
}

double* maximum(double* a, int size) {
    if (size == 0)
        return nullptr;

    double* maxPtr = a;
    double* p = a;

    for (int i = 1; i < size; ++i) {
        if (*p > *maxPtr)
            maxPtr = p;
        p++;
    }

    return maxPtr;
}

double* minimum(double* a, int size) {
    if (size == 0)
        return nullptr;

    double* minPtr = a;
    double* p = a;

    for (int i = 1; i < size; ++i) {
        if (*p < *minPtr)
            minPtr = p;
        p++;
    }

    return minPtr;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size.\n";
        return 1;
    }

    double* array = new double[size];

    cout << "Enter " << size << " floating-point values: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    double avg = average(array, size);
    cout << "Average is " << avg << endl;

    double* maxPtr = maximum(array, size);
    cout << "Maximum value is element #" << (maxPtr - array) << ": " << *maxPtr << endl;

    double* minPtr = minimum(array, size);
    cout << "Minimum value is element #" << (minPtr - array) << ": " << *minPtr << endl;

    delete[] array;

    return 0;
}
