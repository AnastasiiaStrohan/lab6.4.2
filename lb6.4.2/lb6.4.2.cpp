#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


double* createArray(int n) {
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    return arr;
}


void printArray(const double* arr, int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(8) << arr[i];
    }
    cout << endl;
}


int countNegative(const double* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}


int findMinAbsIndex(const double* arr, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) < abs(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}


double sumAfterMinAbs(const double* arr, int minIndex, int n) {
    double sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += abs(arr[i]);
    }
    return sum;
}


void replaceNegativesWithSquares(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = arr[i] * arr[i];
        }
    }
}


void collectNegativeElements(const double* arr, vector<double>& negatives, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives.push_back(arr[i]);
        }
    }
}


void sortNegatives(double* arr, int n) {
    vector<double> negatives;
    collectNegativeElements(arr, negatives, n);

    sort(negatives.begin(), negatives.end());

   
    for (int i = 0, negIndex = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = negatives[negIndex++];
        }
    }
}

int main() {
    int n;
    cout << "size : ";
    cin >> n;

   
    double* arr = createArray(n);

    
    printArray(arr, n);

    
    int negativeCount = countNegative(arr, n);
    cout << "negative elements: " << negativeCount << endl;

    
    int minAbsIndex = findMinAbsIndex(arr, n);
    cout << "Min: " << arr[minAbsIndex] << " at index: " << minAbsIndex << endl;

    
    double sumAfterMinAbsValue = sumAfterMinAbs(arr, minAbsIndex, n);
    cout << "Sum : " << sumAfterMinAbsValue << endl;

   
    replaceNegativesWithSquares(arr, n);

    
    sortNegatives(arr, n);

    
    printArray(arr, n);

    
    delete[] arr;

    return 0;
}
